#include <stdlib.h>
/* Command Types: */
typedef enum { cm_simple, cm_connection } command_type;

typedef enum { r_output_direction, r_input_direction, r_inputa_direction, r_reading_until, r_appending_to } r_instruction;

typedef struct g_list {
  struct g_list *next;
} GENERIC_LIST;

/* A structure which represents a word. */
typedef struct word_desc {
  char *word;			/* Zero terminated string. */
  int quoted;			/* Non-zero means single, double, or back quote
				   or backslash is present. */
  int assignment;		/* Non-zero means that this word contains an assignment. */
} WORD_DESC;

/* A linked list of words. */
typedef struct word_list {
  struct word_list *next;
  WORD_DESC *word;
} WORD_LIST;

 typedef struct redirectee {
  	long dest;                    /* Place to redirect REDIRECTOR to, or ... */
  	WORD_DESC *filename;          /* filename to redirect to. */
} REDIRECTEE;

/* What a redirection descriptor looks like.  If FLAGS is IS_DESCRIPTOR,
   then we use REDIRECTEE.DEST, else we use the file specified. */
typedef struct redirect {
  struct redirect *next;	/* Next element, or NULL. */
  int redirector;		/* Descriptor to be redirected. */
  int flags;			/* Flag value for `open'. */
  REDIRECTEE redirectee;
  r_instruction  instruction; /* What to do with the information. */
} REDIRECT;

/* An element used in parsing.  A single word or a single redirection.
   This is an ephemeral construct. */
typedef struct element {
  WORD_DESC *word;
  REDIRECT *redirect;
} ELEMENT;

/* What a command looks like. */
typedef struct command {
  command_type type;	/* IF CONNECTION or SIMPLE. */
  int flags;			/* Flags controlling execution environment. */
  union {
    struct connection *Connection;
    struct simple_com *Simple;
  } value;
  REDIRECT *redirects;		/* Special redirects for FOR CASE, etc. */
} COMMAND;

/* The "simple" command.  Just a collection of words and redirects. */
typedef struct simple_com {
  WORD_LIST *words;		/* The program name, the arguments, variable assignments, etc. */
  REDIRECT *redirects;		/* Redirections to perform. */
} SIMPLE_COM;

/* Structure used to represent the CONNECTION type. */
typedef struct connection {
  COMMAND *first;		/* Pointer to the first command. */
  COMMAND *second;		/* Pointer to the second command. */
  int connector;		/* What separates this command from others. */
} CONNECTION;

extern COMMAND *global_command;

/* Each child of the shell is remembered in a STRUCT PROCESS.  A chain of
   such structures is a pipeline.  The chain is circular. */
typedef struct process {
  struct process *next;	/* Next process in the pipeline.  A circular chain. */
  int pid;		/* Process ID. */
  union wait status;	/* The status of this command as returned by wait. */
  int running;		/* Non-zero if this process is running. */
  char *command;	/* The particular program that is running. */
} PROCESS;