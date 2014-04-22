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