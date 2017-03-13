/*
** write_content.c for corewar in /home/auzou_t/CPE_2014_corewar/asm
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 13:41:30 2014 Thibaud Auzou
** Last update Wed Dec 10 17:16:49 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "lib.h"

int		write_content(t_list **list, int fd)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (write_ins(tmp->ins, fd) == ERROR)
	return (ERROR);
      if (!byte_code_not_needed(tmp->ins))
	{
	  if (write_byte_code(tmp->code_byte, fd) == ERROR)
	    return (ERROR);
	}
      if (write_params(tmp, tmp->params, fd) == ERROR)
	return (ERROR);
      tmp = tmp->next;
    }
  return (OK);
}

int		write_ins(char *str, int fd)
{
  int		i;
  char		res;

  i = 0;
  res = 0;
  while (i < NB_INS)
    {
      if (my_strcmp(str, op_tab[i].mnemonique) == 0)
	res = op_tab[i].code;
      i++;
    }
  if (write(fd, &res, 1) == -1)
    return (ERROR);
  return (OK);
}

int		write_byte_code(char nb, int fd)
{
  if (write(fd, &nb, 1) == -1)
    return (ERROR);
  return (OK);
}

int		write_params(t_list *tmp, t_param *p, int fd)
{
  t_swap	u;

  while (p != NULL)
    {
      u.nb = get_param_value(tmp, p->param);
      if (write(fd, &(u.buff[4 - p->param_size]), p->param_size) == -1)
	return (ERROR);
      p = p->next;
    }
  return (OK);
}
