/*
** list_param.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/vieira_q/src
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sat Dec 13 03:09:32 2014 quentin vieira
** Last update Sun Dec 14 20:34:22 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"
#include "op.h"

int		add_to_lparam(t_param **list, char *inst, int *size, int i)
{
  t_param	*e;

  if ((e = malloc(sizeof(t_param))) == NULL)
    return (ERROR);
  get_value_lparam(e->val, inst, size[i]);
  e->param_size = size[i];
  e->param_size == 1 ? e->param = my_strdup("r") : (e->param = my_strdup("%"));
  if (e->param == NULL)
    return (ERROR);
  inst = inst + size[i];
  i++;
  if ((*list) == NULL)
    (*list) = e;
  else
    (*list)->next = e;
  e->prev = *list;
  e->next = NULL;
  if (i < 5 && size[i] != 0)
    return (add_to_lparam(&e, inst, size, i));
  return (0);
}

int		get_value_lparam(char *tab_val, char *inst, int nb)
{
  int		i;

  i = 0;
  while (i < MAX_ARGS_NUMBER)
     tab_val[i++] = 0;
  i = 0;
  while (i < nb)
    {
      tab_val[i] = inst[i];
      i++;
    }
  return (0);
}

t_param	*set_lparam_to_first(t_param *list)
{
  while (list->prev != NULL)
    list = list->prev;
  return (list);
}

void		print_lparam_list(t_param **list, int fd, int st)
{
  t_param	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (st != 1)
	my_putstr_fd(tmp->param, fd);
      else
	{
	  if (tmp->param_size != 2)
	    my_putstr_fd(tmp->param, fd);
	}
      my_put_nbr_fd(get_val(tmp->val, tmp->param_size), fd);
      if (tmp->next != NULL)
	my_putstr_fd(",", fd);
      tmp = tmp->next;
    }
  return ;
}

int		get_val(char *val, int size)
{
  t_swap	u;
  int		ct;
  int		i;

  ct = 0;
  i = size - 1;
  while (ct < size)
    {
      u.buff[ct] = val[i];
      ct++;
      i--;
    }
  while (ct < MAX_ARGS_NUMBER)
    u.buff[ct++] = 0;
  if (u.buff[size - 1] == -1 && size == 4)
    u.nb = (0xFFFFFFFF - u.nb + 1) * -1;
  else if (u.buff[size - 1] == -1 && size == 2)
    u.nb = (0xFFFF - u.nb + 1) * -1;
  return (u.nb);
}
