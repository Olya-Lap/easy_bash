typedef union {
  long dest;                    /* Place to redirect REDIRECTOR to, or ... */
  WORD_DESC *filename;          /* filename to redirect to. */
} REDIRECTEE;

typedef struct redirect {
  struct redirect *next;        /* Next element, or NULL. */
  int redirector;               /* Descriptor to be redirected. */
  int flags;                    /* Flag value for `open'. */
  enum r_instruction  instruction; /* What to do with the information. */
  REDIRECTEE redirectee;        /* File descriptor or filename */
  char *here_doc_eof;           /* The word that appeared in <<foo. */
} REDIRECT;
