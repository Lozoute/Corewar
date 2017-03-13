/*
** get_content.c for corewar in /home/auzou_t/CPE_2014_corewar/asm
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Mon Dec  8 21:43:58 2014 Thibaud Auzou
** Last update Sat Dec 13 16:10:10 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

int		get_content(t_list **list, int fd)
{
  char		*str;
  t_list	*elem;
  t_list	*tmp;

  tmp = *list;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (is_not_empty(str))
	{
	  if ((elem = malloc(sizeof(t_list))) == NULL)
	    return (ERROR);
	  if (fill_list_elem(elem, str, fd) == ERROR)
	    return (ERROR);
	  if (*list == NULL)
	    *list = elem;
	  else
	    tmp->next = elem;
	  elem->prev = tmp;
	  elem->next = NULL;
	  tmp = elem;
	}
      free(str);
    }
  return (OK);
}

int		is_not_empty(char *str)
{
  int		i;
  int		com;

  com = 0;
  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      if (str[0] == '#' || str[0] == ';')
	return (0);
      if (str[i] == '#' || str[i] == ';')
	com = 1;
      if (str[i] != '\t' && str[i] != ' ' && com == 0)
	return (1);
      i++;
    }
  return (0);
}

char		*get_label_name(char *str, int *i)
{
  int		j;
  char		*res;

  j = 0;
  while (str && str[j] && str[j] != ':')
    j++;
  if (str[j] == ':')
    {
      if (str[j + 1] == '\0')
	*i = *i + 1;
      res = my_strndup(str, j);
      shift_str(str, j + 1);
      return (res);
    }
  return (NULL);
}

int		shift_str(char *str, int i)
{
  int		j;

  j = 0;
  while (str[i] != '\0')
    {
      str[j] = str[i];
      i++;
      j++;
    }
  str[j] = '\0';
  return (0);
}

char		**fetch_ins(int fd)
{
  char		*str;

  str = NULL;
  while (!is_not_empty(str))
    {
      if ((str = get_next_line(fd)) == NULL)
	return (NULL);
    }
  return (my_str_to_wordtab(str));
}
