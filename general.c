#include "types.h"
/* Reverse the chain of structures in LIST.  Output the new head
   of the chain.  You should always assign the output value of this
   function to something, or you will lose the chain. */
GENERIC_LIST *reverse_list (GENERIC_LIST *list)
{
  GENERIC_LIST *next, *prev = (GENERIC_LIST *)NULL;

  while (list) {
    next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return (prev);
}