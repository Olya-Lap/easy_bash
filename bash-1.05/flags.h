/* flags.h -- a list of all the flags that the shell knows about.  You add
   a flag to this program by adding the name here, and in flags.c. */

/* Welcome to the world of Un*x, where everything is slightly
   backwards. */
#define FLAG_ON '-'
#define FLAG_OFF '+'

#define FLAG_ERROR -1

/* The thing that we build the array of flags out of. */
struct flags_alist {
  char *name;
  int *value;
};

extern struct flags_alist shell_flags[];

extern int
  mark_modified_vars, exit_immediately_on_error, disallow_filename_globbing,
  locate_commands_in_functions, place_keywords_in_env, read_but_dont_execute,
  just_one_command, unbound_vars_is_error, echo_input_at_read,
  echo_command_at_execute, lexical_scoping, no_invisible_vars,
  hashing_disabled, history_expansion, forced_interactive;
