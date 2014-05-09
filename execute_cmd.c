#include <stdio.h>
#include <signal.h>
#include "types.h"

#ifndef savestring
#define savestring(x) (char *)strcpy (malloc (1 + strlen (x)), (x))
#endif
#define NO_PIPE -1

int execute_command (COMMAND *command, int asynchronous, int pipe_in, int pipe_out)
{
  int exec_result;

  /* If a command was being explicitly run in a subshell, or if it is
     a shell control-structure, and it has a pipe, then we do the command
     in a subshell. */

  if (command->subshell)
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
		      exit (1);
		  exit (execute_command (command, asynchronous, NO_PIPE, NO_PIPE));
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
		    return 0;
		  
		  stop_pipeline (asynchronous, (COMMAND *)NULL);

		  if (!asynchronous)
		    return last_command_exit_value = wait_for (paren_pid);
		  else
		  {
		      extern int interactive;
		      if (interactive)
			  describe_pid (paren_pid);
		      return 0;
		  }
	  }
  }

  do_redirections (command->redirects, 1, 1);

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
		    exec_result = execute_command (tc, 1, pipe_in, pipe_out);
		    if (command->value.Connection->second)
		      exec_result =	execute_command (command->value.Connection->second, asynchronous, pipe_in, pipe_out);
	  	}
	  	break;

		case ';':
		  /* Just call execute command on both of them. */
		  execute_command (command->value.Connection->first);
		  exec_result = execute_command (command->value.Connection->second, asynchronous, pipe_in, pipe_out);
	  	break;

		case '|':
		{
		    /* Make a pipeline between the two commands. */
		    int fildes[2];
		    if (pipe (fildes) < 0)
		    {
				fprintf(stderr,  ("Pipe error %d", errno);
				exec_result = 1;
		    }
		    else
		    {
				execute_command (command->value.Connection->first, asynchronous, pipe_in, fildes[1]);
				exec_result = execute_command (command->value.Connection->second, asynchronous, fildes[0], pipe_out);
		    }
		}
		break;
	
		default:
		  fprintf(stderr, "Bad connector `%d'!", command->value.Connection->connector);
		break;
	  }
    break;

    default:
      fprintf(stderr, "execute_command: Bad command type `%d'!", command->type);
    }

  return last_command_exit_value = exec_result;
}

void do_piping (int pipe_in, int pipe_out)
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

void do_redirections (REDIRECT *list, int for_real)
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

void close_pipes (int in, int out)
{
  if (in >= 0) close (in);
  if (out >= 0) close (out);
}

void do_redirection (REDIRECT *redirect, int for_real)
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

/* Fork, handling errors.  Returns the pid of the newly made child, or 0.
   COMMAND is just for remembering the name of the command; we don't do
   anything else with it.  ASYNC_P says what to do with the tty.  If
   non-zero, then don't give it away. */
int make_child (char *command, int async_p)
{
  int pid, oldmask;
  
  oldmask = sigblock (sigmask (SIGINT) | sigmask (SIGCHLD));

  making_children ();

  if ((pid = fork ()) < 0)
  {
      sigsetmask (oldmask);
      fprintf(stderr, "Memory exhausted or process overflow!");
  }
 
  if (!pid)
  {
      /* In the child.  Give this child the right process group, set the
	 signals to the default state for a new process. */
      signal (SIGINT, SIG_DFL);
      signal (SIGQUIT, SIG_DFL);
      signal (SIGTERM, SIG_DFL);

	  /* All processes in this pipeline belong in the same
	     process group. */

	  if (!pipeline_pgrp)	/* Then this is the first child. */
	    pipeline_pgrp = getpid ();

	  /* Check for running command in backquotes. */
	  if (pipeline_pgrp == shell_pgrp)
	    {
	      signal (SIGTSTP, SIG_IGN);
	      signal (SIGTTOU, SIG_IGN);
	      signal (SIGTTIN, SIG_IGN);
	    }
	  else
	    {
	      signal (SIGTSTP, SIG_DFL);
	      signal (SIGTTOU, SIG_DFL);
	      signal (SIGTTIN, SIG_DFL);
	    }
	
	  if (!async_p)
	    give_terminal_to (pipeline_pgrp);

	  setpgrp (0, pipeline_pgrp);

      if (async_p)
		last_asynchronous_pid = getpid ();
  }
  else
  {
      /* In the parent.  Remember the pid of the child just created
	 as the proper pgrp if this is the first child. */

	  if (!pipeline_pgrp)
	      pipeline_pgrp = pid;
	  setpgid (pid, pipeline_pgrp);

      /* Place all processes into the jobs array regardless of the
	 state of job_control.  */
      add_process (command, pid);

      if (async_p)
		last_asynchronous_pid = pid;

      last_made_pid = pid;
  }
  sigsetmask (oldmask);
  return (pid);
}

/* Add this process to the chain being built in the_pipeline.
   NAME is the command string that will be exec'ed later.
   PID is the process id of the child. */
void add_process (char *name, int pid)
{
  PROCESS *t = (PROCESS *)malloc (sizeof (PROCESS));

  t->next = the_pipeline;
  t->pid = pid;
  t->status.w_status = 0;
  t->running = 1;
  t->command = name;
  the_pipeline = t;

  if (!(t->next))
  {
      t->next = t;
  }
  else
  {
      PROCESS *p = t->next;

      while (p->next != t->next) p = p->next;
      p->next = t;
  }
}

void make_command_string (COMMAND *command)
{
  if (!command)
  {
      cprintf ("");
  }
  else
  {
    if (command->subshell)
		cprintf ("( ");

    switch (command->type)
	{
		case cm_simple:
		  WORD_LIST *words = command->value.Simple->words
		  while (list)
    	  {
      		cprintf ("%s", list->word->word);
      		list = list->next;
      		if (list)
				cprintf ("%s", " ");
    	  }
		  break;

		case cm_connection: 
		  make_command_string (command->value.Connection->first);

		  switch (command->value.Connection->connector)
		  {
		    case '&':
		    case '|':
		    {
				char c = command->value.Connection->connector;
				cprintf ("%c", c);
				if (c != '&' || command->value.Connection->second)
				{
				    cprintf (" ");
				}
		    }
		    break;
		
		    case ';':
			  cprintf (";");
		    break;

		    default:
		      cprintf ("OOPS!  Bad connector `%d'!",
			       command->value.Connection->connector);
		    break;
	      }

	  	  make_command_string (command->value.Connection->second);
	  	break;
      
		default:
		  fprintf (stderr, "OOPS!  Bad command type `%d'!", command->type);
		break;
	}

	if (command->subshell)
		cprintf (" )");

     if (command->redirects)
		cprintf ("some redirects");
    }
}