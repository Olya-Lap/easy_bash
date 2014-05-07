#include <stdio.h>
#include "types.h"

execute_command (COMMAND *command, int asynchronous, int pipe_in, int pipe_out)
{
  int exec_result;
  REDIRECT *my_undo_list = (REDIRECT *)NULL;

  /* If a command was being explicitly run in a subshell, or if it is
     a shell control-structure, and it has a pipe, then we do the command
     in a subshell. */

  if (command->subshell ||
      (shell_control_structure (command->type) &&
       (pipe_out != NO_PIPE || pipe_in != NO_PIPE || asynchronous)))
  {
      int paren_pid;

      /* Fork a subshell, turn off the subshell bit, turn off job
	 control and call execute_command () on the command again. */
      paren_pid = make_child (savestring (make_command_string (command)), asynchronous);
      if (paren_pid == 0)
	  {
		  extern int interactive, login_shell;

		  command->subshell = 0;

		  /* Don't fork again, we are already in a subshell. */
		  asynchronous = 0;

		  /* Subshells are neither login nor interactive. */
		  login_shell = interactive = 0;
#ifdef JOB_CONTROL
		  /* Delete all traces that there were any jobs running.  This is
		     only for subshells. */
		  without_job_control ();
#endif
		  do_piping (pipe_in, pipe_out);
		  if (command->redirects)
		    if (!(do_redirections (command->redirects, 1, 0) == 0))
		      exit (EXECUTION_FAILURE);
		  exit (execute_command_internal (command, asynchronous, NO_PIPE, NO_PIPE));
	  }
      else
	  {
		  close_pipes (pipe_in, pipe_out);

		  /* If we are part of a pipeline, and not the end of the pipeline,
		     then we should simply return and let the last command in the
		     pipe be waited for.  If we are not in a pipeline, or are the
		     last command in the pipeline, then we wait for the subshell
		     and return its exit status as usual. */
		  if (pipe_out != NO_PIPE)
		    return (EXECUTION_SUCCESS);
		  
		  stop_pipeline (asynchronous, (COMMAND *)NULL);

		  if (!asynchronous)
		    return (last_command_exit_value = wait_for (paren_pid));
		  else
		  {
		      extern int interactive;
		      if (interactive)
			  describe_pid (paren_pid);
		      return (EXECUTION_SUCCESS);
		  }
	  }
  }

  do_redirections (command->redirects, 1, 1);
  my_undo_list = (REDIRECT *)copy_redirects (redirection_undo_list);

  switch (command->type)
  {
    case cm_simple:
    {
		extern int last_asynchronous_pid, last_made_pid;
		int last_pid = last_made_pid;
	
#ifdef JOB_CONTROL
		extern int already_making_children;
#endif 
		exec_result = execute_simple_command (command->value.Simple, pipe_in, pipe_out, asynchronous);

	/* If we forked to do the command, then we must
	   wait_for() the child. */
#ifdef JOB_CONTROL
		if (already_making_children && pipe_out == NO_PIPE)
#else
	  	if (pipe_out == NO_PIPE)
#endif
	    {
	      	if (last_pid != last_made_pid)
			{
				stop_pipeline (asynchronous, (COMMAND *)NULL);

				if (asynchronous)
				{
				    extern int interactive;
				    if (interactive)
						describe_pid (last_made_pid);
				}
				else
			    	exec_result = wait_for (last_made_pid);
			}
	    }
    }
    break;

    case cm_connection:
      switch (command->value.Connection->connector)
	  {
	  /* Do the first command asynchronously. */
		case '&':
	  	{
		    COMMAND *tc = command->value.Connection->first;
#ifndef JOB_CONTROL
		    {
		      REDIRECT *tr = make_redirection (0, r_inputa_direction, make_word ("/dev/null"));
		      tr->next = tc->redirects;
		      tc->redirects = tr;
		    }
#endif				/* !JOB_CONTROL */
		    exec_result = execute_command_internal (tc, 1, pipe_in, pipe_out);
		    if (command->value.Connection->second)
		      exec_result =
			execute_command_internal (command->value.Connection->second,
						  asynchronous, pipe_in, pipe_out);
	  	}
	  	break;

		case ';':
		  /* Just call execute command on both of them. */
		  execute_command (command->value.Connection->first);
		  exec_result = execute_command_internal (command->value.Connection->second, asynchronous, pipe_in, pipe_out);
	  	break;

		case '|':
		{
		    /* Make a pipeline between the two commands. */
		    int fildes[2];
		    if (pipe (fildes) < 0)
		    {
				report_error ("Pipe error %d", errno);
				exec_result = EXECUTION_FAILURE;
		    }
		    else
		    {
				execute_command_internal (command->value.Connection->first, asynchronous, pipe_in, fildes[1]);
				exec_result = execute_command_internal (command->value.Connection->second, asynchronous, fildes[0], pipe_out);
		    }
		}
		break;
	
		default:
		  fprintf(stderr, "Bad connector `%d'!", command->value.Connection->connector);
		  longjmp (top_level, DISCARD);
		break;
	  }
    break;

    default:
      fprintf(stderr, "execute_command: Bad command type `%d'!", command->type);
    }

  if (my_undo_list)
  {
      do_redirections (my_undo_list, 1, 0);
      dispose_redirects (my_undo_list);
  }
  return (last_command_exit_value = exec_result);
}

do_piping (int pipe_in, int pipe_out)
{
  if (pipe_in != NO_PIPE) {
    dup2 (pipe_in, 0);
    close (pipe_in);
  }
  if (pipe_out != NO_PIPE) {
    dup2 (pipe_out, 1);
    close (pipe_out);
    if (pipe_out == -2)
      dup2 (1, 2);
  }
}

do_redirections (REDIRECT *list, int for_real)
{
  int error;
  REDIRECT *temp = list;

  while (temp)
  {
      error = do_redirection (temp, for_real);
      if (error)
  	  {
		  fprintf(stderr, "ERROR: %s", temp->redirectee.filename->word);
		  return (error);
  	  }

      temp = temp->next;
  }
  return (0);
}

do_redirection (REDIRECT *redirect, int for_real)
{
  WORD_DESC *redirectee = redirect->redirectee.filename;
  int redirector = redirect->redirector;
  char *redirectee_word = 0;
  r_instruction ri = redirect->instruction;

  int fd;

  switch (ri)
  {
    case r_output_direction:
    case r_appending_to:
    case r_input_direction:
    case r_inputa_direction:		/* command &>filename */

      if (!(redirectee_word = redirection_expand (redirectee)))
		return (AMBIGUOUS_REDIRECT);

      fd = open (redirectee_word, redirect->flags, 0666);
      free (redirectee_word);

      if (fd < 0 )
		return (errno);

      if (for_real)
	  {
		  if (fd != redirector && dup2 (fd, redirector) < 0)
		    return (errno);
	  }
      if (fd != redirector)
		close (fd);

      break;
    }
  return (0);
}
