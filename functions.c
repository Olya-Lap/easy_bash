#include "types.h"
#include <stdio.h>

COMMAND * make_command (command_type type, SIMPLE_COM *pointer)
{
  COMMAND *temp = (COMMAND *)malloc (sizeof (COMMAND));
  temp->type = type;
  temp->value.Simple = pointer;
  temp->subshell = 0;
  temp->redirects = (REDIRECT *)NULL;
  return (temp);
}

COMMAND * command_connect (COMMAND *com1, *com2, int connector)
{
  CONNECTION *temp = (CONNECTION *)malloc (sizeof (CONNECTION));
  temp->connector = connector;
  temp->first = com1;
  temp->second = com2;
  return (make_command (cm_connection, temp));
}

WORD_LIST * make_word_list (WORD_DESC *word, WORD_LIST *link)
{
  WORD_LIST *temp = (WORD_LIST *)malloc (sizeof (WORD_LIST));
  temp->word = word;
  temp->next = link;
  return (temp);
}

WORD_LIST * add_string_to_list (char *string, WORD_LIST *list)
{
  WORD_LIST *temp = (WORD_LIST *)malloc (sizeof (WORD_LIST));
  temp->word = make_word (string);
  temp->next = list;
  return (temp);
}

REDIRECT * make_redirection (source, enum r_instruction instruction, dest)
{
  REDIRECT *temp = (REDIRECT *)malloc (sizeof (REDIRECT));
  int kill_leading = 0;

  /* First do the common cases. */
  temp->redirector = source;
  temp->redirectee.dest = dest;
  temp->instruction = instruction;
  temp->next = (REDIRECT *)NULL;

  switch (instruction) {

  case r_output_direction:  /* >foo */
    temp->flags = O_TRUNC | O_WRONLY | O_CREAT;
    break;

  case r_input_direction: /* <foo */
 // case r_inputa_direction:  /* foo & makes this. */
   // temp->flags = O_RDONLY;
    //break;

  //case r_duplicating:   /* 1<&2 */
    
  //case r_err_and_out:   /* command &>filename */
   // temp->flags = O_TRUNC | O_WRONLY | O_CREAT;
    //break;

  default:
    report_error ("Redirection instruction from yyparse () '%d' is\n\
out of range in make_redirection ().", instruction);
    abort ();
    break;
  }
  return (temp);
}

/* Reverse the word list and redirection list in the simple command
   has just been parsed.  It seems simpler to do this here the one
   time then by any other method that I can think of. */
COMMAND * clean_simple_command (COMMAND *command)
{
  if (command->type != cm_simple)
    programming_error ("clean_simple_command () got a command with type %d.", command->type);
  else {
    command->value.Simple->words =
      (WORD_LIST *)reverse_list (command->value.Simple->words);
    command->value.Simple->redirects = 
      (REDIRECT *)reverse_list (command->value.Simple->redirects);
  }
  return (command);
}

/* Return a command which is the connection of the word or redirection
   in ELEMENT, and the command * or NULL in COMMAND. */
COMMAND * make_simple_command (ELEMENT element, COMMAND *command)
{
  /* If we are starting from scratch, then make the initial command
     structure.  Also note that we have to fill in all the slots, since
     malloc doesn't return zeroed space. */
  if (!command)
    {
      SIMPLE_COM *temp = (SIMPLE_COM *)malloc (sizeof (SIMPLE_COM));
      temp->words = (WORD_LIST *)NULL;
      temp->redirects = (REDIRECT *)NULL;
      command = (COMMAND *)malloc (sizeof (COMMAND));
      command->type = cm_simple;
      command->redirects = (REDIRECT *)NULL;
      command->subshell = 0;
      command->value.Simple = temp;
    }
  if (element.word)
    {
      WORD_LIST *tw = (WORD_LIST *)malloc (sizeof (WORD_LIST));
      tw->word = element.word;
      tw->next = command->value.Simple->words;
      command->value.Simple->words = tw;
    }
  else
    {
      element.redirect->next = command->value.Simple->redirects;
      command->value.Simple->redirects = element.redirect;
    }
  return (command);
}
