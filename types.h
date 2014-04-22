/* Command Types: */
enum command_type { cm_simple, cm_connection };

enum r_instruction { r_output_direction, r_input_direction };

/* A structure which represents a word. */
typedef struct word_desc {
  char *word;			/* Zero terminated string. */
  int dollar_present;		/* Non-zero means dollar sign present. */
  int quoted;			/* Non-zero means single, double, or back quote
				   or backslash is present. */
  int assignment;		/* Non-zero means that this word contains an assignment. */
} WORD_DESC;
//??

/* A linked list of words. */
typedef struct word_list {
  struct word_list *next;
  WORD_DESC *word;
} WORD_LIST;

typedef union {
  long dest;                    /* Place to redirect REDIRECTOR to, or ... */
  WORD_DESC *filename;          /* filename to redirect to. */
} REDIRECTEE;

/* What a redirection descriptor looks like.  If FLAGS is IS_DESCRIPTOR,
   then we use REDIRECTEE.DEST, else we use the file specified. */
typedef struct redirect {
  struct redirect *next;	/* Next element, or NULL. */
  int redirector;		/* Descriptor to be redirected. */
  int flags;			/* Flag value for `open'. */
  enum r_instruction  instruction; /* What to do with the information. */
  char *here_doc_eof;		/* The word that appeared in <<foo. */
} REDIRECT;

/* An element used in parsing.  A single word or a single redirection.
   This is an ephemeral construct. */
typedef struct element {
  WORD_DESC *word;
  REDIRECT *redirect;
} ELEMENT;

union {
    struct connection *Connection;
    struct simple_com *Simple;
 } VALUE;

/* What a command looks like. */
typedef struct command {
  enum command_type type;	/* FOR CASE WHILE IF CONNECTION or SIMPLE. */
  int subshell;			/* Non-zero means execute in a subshell. */
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