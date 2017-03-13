/*
** get_param_value.c for corewar in /home/auzou_t/CPE_2014_corewar/asm
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 16:40:09 2014 Thibaud Auzou
** Last update Sat Dec 13 16:38:57 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "lib.h"

int		get_param_value(t_list *tmp, char *param)
{
  if (param == NULL)
    return (0);
  if (param[0] == ':')
    return (my_swap_endian(get_value_label(&(param[1]), tmp)));
  if (param[1] == ':')
    return (my_swap_endian(get_value_label(&(param[2]), tmp)));
  if (param[0] == '%')
    return (my_swap_endian(my_getnbr(&(param[1]))));
  if (param[0] == 'r')
    return (my_swap_endian(my_getnbr(&(param[1]))));
  return (my_swap_endian(my_getnbr(param)));
}

int		get_value_label(char *label, t_list *tmp)
{
  t_list	*tmp2;
  int		res;

  if (tmp == NULL || (tmp->label != NULL && my_strcmp(label, tmp->label) == 0))
    return (0);
  tmp2 = tmp;
  res = 0;
  while (tmp2 != NULL)
    {
      if (tmp2->label != NULL && my_strcmp(label, tmp2->label) == 0)
	return (res);
      res += tmp2->tot_bytes;
      tmp2 = tmp2->next;
    }
  tmp2 = tmp->prev;
  res = 0;
  while (tmp2 != NULL)
    {
      res += tmp2->tot_bytes;
      if (tmp2->label != NULL && my_strcmp(label, tmp2->label) == 0)
	return (-1 * res);
      tmp2 = tmp2->prev;
    }
  return (0);
}
