/*
** list_champ.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/list
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 17:55:52 2014 Thibaud Auzou
** Last update Sun Dec 14 21:40:03 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "init.h"

int		add_champ_to_list(char *name, int fd, t_champ **list)
{
  t_champ	*elem;

  if ((elem = malloc(sizeof(t_champ))) == NULL)
    {
      my_putstre("Could not malloc\n");
      return (-1);
    }
  elem->champ_name = name;
  elem->champ_fd = fd;
  elem->size_prog = 0;
  elem->comment = NULL;
  elem->my_inst = NULL;
  if (*list != NULL)
    (*list)->next = elem;
  elem->next = NULL;
  elem->prev = (*list);
  (*list) = elem;
  return (0);
}

t_champ	*add_elem_to_champ(t_champ *list,
				   char *comment,
				   int size,
				   t_options options)
{
  int		i;

  i = 1;
  list->size_prog = size;
  list->comment = comment;
  list->options = options;
  list->alive = 0;
  list->pc = 0;
  list->cycle = 0;
  list->carry = 0;
  if (REG_NUMBER > 0)
    {
      list->reg[0] = options.num;
      while (i < REG_NUMBER)
	{
	  list->reg[i] = 0;
	  i++;
	}
    }
  return (list);
}

t_champ	*set_list_to_first(t_champ *list)
{
  if (list == NULL)
    return (NULL);
  while (list->prev != NULL)
    list = list->prev;
  return (list);
}
