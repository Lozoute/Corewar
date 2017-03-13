/*
** list_champ.c for  in /home/vieira_q/Prog_elem_C/Corewar/vm
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec  7 22:59:36 2014 quentin vieira
** Last update Sun Dec 14 20:34:01 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"
#include "corewar.h"

int		add_champ_to_list(char *name, int fd, t_champ **list)
{
  t_champ	*elem;

  if ((elem = malloc(sizeof(t_champ))) == NULL)
    {
      my_put_error("Could not malloc\n");
      return (-1);
    }
  elem->champ_name = name;
  elem->champ_fd = fd;
  elem->size_prog = 0;
  elem->comment = NULL;
  elem->my_inst = NULL;
  if (*list == NULL)
    {
      elem->next = NULL;
      elem->prev = NULL;
    }
  else
    {
      elem->next = NULL;
      elem->prev = (*list);
      (*list)->next = elem;
    }
  (*list) = elem;
  return (0);
}

t_champ	*add_elem_to_champ(t_champ *list,
				   char *comment,
				   int size)
{
  list->size_prog = size;
  list->comment = comment;
  return (list);
}

void		print_champ_list(t_champ **my_list)
{
  t_champ	*tmp;

  tmp = (*my_list);
  tmp = set_list_to_first(tmp);
  while (tmp != NULL)
    {
      my_putstr_fd(".name", tmp->champ_fd);
      my_putstr_fd("\t", tmp->champ_fd);
      my_putstr_fd("\"", tmp->champ_fd);
      my_putstr_fd(tmp->champ_name, tmp->champ_fd);
      my_putstr_fd("\"\n", tmp->champ_fd);
      my_putstr_fd(".comment", tmp->champ_fd);
      my_putstr_fd("\t", tmp->champ_fd);
      my_putstr_fd("\"", tmp->champ_fd);
      my_putstr_fd(tmp->comment, tmp->champ_fd);
      my_putstr_fd("\"\n\n", tmp->champ_fd);
      print_list_inst(&(tmp->my_inst), tmp->champ_fd);
      my_putstr(COLOR_GREEN);
      my_putstr(tmp->champ_name);
      my_putstr(" done \n");
      my_putstr(COLOR_RESET);
      tmp = tmp->next;
    }
  return ;
}

t_champ	*set_list_to_first(t_champ *list)
{
  if (list == NULL)
    return (NULL);
  while (list->prev != NULL)
    list = list->prev;
  return (list);
}
