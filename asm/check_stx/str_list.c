/*
** line_list.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Tue Dec  9 13:24:19 2014 florian hellegouarch
** Last update Sun Dec 14 22:48:06 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "asm.h"

void		free_list(t_str_list *l)
{
  t_str_list	*l2;

  if (l)
    {
      if (l->str)
        free(l->str);
      l2 = l;
      l = l->next;
      free_list(l);
      free(l2);
    }
}

void		add_to_list(t_str_list **list, char *line)
{
  t_str_list	*l;
  t_str_list	*pt;

  l = check_malloc(sizeof(t_str_list));
  l->str = line;
  l->next = NULL;
  if (*list)
    {
      pt = *list;
      while (pt->next)
	pt = pt->next;
      pt->next = l;
    }
  else
    *list = l;
}

t_str_list	*file_to_list(int fd)
{
  t_str_list	*list;
  char		*line;
  int		limit;

  limit = 5000;
  list = NULL;
  while ((line = get_next_line(fd)))
    {
      limit--;
      if (limit <= 0)
	{
	  my_putstr(COLOR_RED);
	  my_putstre("File too big\n");
	  my_putstr(COLOR_RESET);
	  exit(EXIT_FAILURE);
	}
      add_to_list(&list, line);
    }
  return (list);
}
