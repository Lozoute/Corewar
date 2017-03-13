/*
** list_param.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/list
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 17:57:16 2014 Thibaud Auzou
** Last update Sun Dec 14 06:44:05 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"
#include "lib.h"

int		add_to_lparam(t_param **list, char *inst, int *size, int i)
{
  t_param	*e;

  if ((e = malloc(sizeof(t_param))) == NULL)
    return (ERROR);
  get_value_lparam(e->val, inst, size[i]);
  e->param_size = size[i];
  e->param_size == 1 ? e->param = my_strdup("r") : (e->param = my_strdup("%"));
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
  else if ((u.buff[size - 1]) >> 4 < 0 && size == 1)
    u.nb = (0xFF - u.nb + 1) * -1;
  return (u.nb);
}
