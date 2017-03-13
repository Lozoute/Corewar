/*
** remove_comment.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Tue Dec  9 17:50:21 2014 florian hellegouarch
** Last update Sat Dec 13 19:22:12 2014 Thibaud Auzou
*/

#include "asm.h"

void	rm_str(char *str)
{
  char	*pt;

  pt = str;
  while (*pt && *pt != '"')
    pt++;
  while (*pt)
    *str++ = *pt++;
  *str = 0;
}

void	remove_comment(t_str_list *l)
{
  char	*line;

  while (l)
    {
      line = l->str;
      while (*line && *line != '#' && *line != ';')
	{
	  if (*line == '"')
	    rm_str(++line);
	  line++;
	}
      *line = 0;
      l = l->next;
    }
}
