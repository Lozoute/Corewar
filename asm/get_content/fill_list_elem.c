/*
** fill_list_elem.c for corewar in /home/auzou_t/CPE_2014_corewar/asm
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Mon Dec  8 22:12:57 2014 Thibaud Auzou
** Last update Sat Dec 13 16:08:20 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

int		fill_list_elem(t_list *elem, char *str, int fd)
{
  char		**tab;
  int		i;

  if ((tab = my_str_to_wordtab(str)) == NULL)
    return (ERROR);
  i = 0;
  elem->label = get_label_name(tab[i], &i);
  if (tab[i] == NULL)
    {
      i = 0;
      free_wordtab(tab);
      if ((tab = fetch_ins(fd)) == NULL)
	return (ERROR);
    }
  elem->ins = my_strdup(tab[i]);
  elem->params = NULL;
  if (fill_elem_params(elem, &(tab[i + 1])) == ERROR)
    return (ERROR);
  get_params_size(elem);
  elem->tot_bytes = get_tot_bytes(elem);
  elem->code_byte = get_code_byte(elem);
  free_wordtab(tab);
  return (OK);
}

int		fill_elem_params(t_list *elem, char **tab)
{
  int		i;
  t_param	*p;
  t_param	*tmp;

  tmp = elem->params;
  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      if ((p = malloc(sizeof(t_param))) == NULL)
	return (ERROR);
      p->param = my_strdup(tab[i]);
      p->param_size = 7;
      p->prev = tmp;
      p->next = NULL;
      if (tmp == NULL)
	elem->params = p;
      else
	tmp->next = p;
      tmp = p;
      i++;
    }
  return (OK);
}

int		get_tot_bytes(t_list *elem)
{
  t_param	*p;
  int		res;

  if (elem == NULL)
    return (0);
  p = elem->params;
  res = 0;
  while (p != NULL)
    {
      res += p->param_size;
      p = p->next;
    }
  if (byte_code_not_needed(elem->ins))
    res += 1;
  else
    res += 2;
  return (res);
}

char		get_code_byte(t_list *elem)
{
  t_param	*p;
  char		res;
  int		i;
  char		tmp;

  if (elem == NULL || byte_code_not_needed(elem->ins))
    return (0);
  p = elem->params;
  res = 0;
  i = 0;
  while (p != NULL)
    {
      if (p->param[0] == 'r')
	tmp = 1;
      else if (p->param[0] == '%')
	tmp = 2;
      else
	tmp = 3;
      tmp = (tmp << (6 - i));
      res = res | tmp;
      i = i + 2;
      p = p->next;
    }
  return (res);
}

int		byte_code_not_needed(char *str)
{
  if (str == NULL)
    return (1);
  if (my_strcmp(str, "live") == 0)
    return (1);
  if (my_strcmp(str, "zjmp") == 0)
    return (1);
  if (my_strcmp(str, "fork") == 0)
    return (1);
  if (my_strcmp(str, "lfork") == 0)
    return (1);
  return (0);
}
