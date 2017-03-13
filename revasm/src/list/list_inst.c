/*
** list_inst.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/vieira_q/src
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Wed Dec 10 17:14:46 2014 quentin vieira
** Last update Sun Dec 14 20:34:16 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

int		add_ins_to_list(t_inst **list, int *size, char *inst, int ct)
{
  t_inst	*elem;
  int		pt_tmp;

  if ((elem = malloc(sizeof(t_inst))) == NULL)
    return (-1);
  elem->label = NULL;
  elem->tot_bytes = size[0] + size[1] + size[2] + size[3] + size[4];
  elem->code_byte = inst[ct + 1];
  elem->params = NULL;
  pt_tmp = ct + size[0] + size[1];
  if (add_to_lparam(&(elem->params), &(inst[pt_tmp]), size, 2) == -1)
    return (ERROR);
  elem->val_ins = inst[ct];
  if ((elem->ins = get_name_inst(inst, ct)) == NULL)
    return (-1);
  elem->next = NULL;
  if ((*list) == NULL)
    elem->prev = NULL;
  else
    {
      elem->prev = (*list);
      (*list)->next = elem;
    }
  (*list) = elem;
  return (0);
}

t_inst	*set_linst_to_first(t_inst *list)
{
  while (list->prev != NULL)
    list = list->prev;
  return (list);
}

void		print_list_inst(t_inst **list, int fd)
{
  t_inst	*tmp;
  int		st;

  st = 0;
  tmp = (*list);
  tmp = set_linst_to_first(tmp);
  while (tmp != NULL)
    {
      if (tmp->val_ins == 0x03 || tmp->val_ins == 0x02)
	st = 1;
      my_putstr_fd("\t", fd);
      my_putstr_fd(tmp->ins, fd);
      my_putstr_fd("\t", fd);
      print_lparam_list(&(tmp->params), fd, st);
      my_putstr_fd("\n", fd);
      st = 0;
      tmp = tmp->next;
    }
}

char	*get_name_inst(char *inst, int ct)
{
  char	*res;

  if (inst[ct] == 0x01)
    res = my_strdup("live");
  else if (inst[ct] == 0x02)
    res = my_strdup("ld");
  else if (inst[ct] == 0x03)
    res = my_strdup("st");
  else if (inst[ct] == 0x04)
    res = my_strdup("add");
  else if (inst[ct] == 0x05)
    res = my_strdup("sub");
  else if (inst[ct] == 0x06)
    res = my_strdup("and");
  else if (inst[ct] == 0x07)
    res = my_strdup("or");
  else if (inst[ct] == 0x08)
    res = my_strdup("xor");
  else if (inst[ct] == 0x09)
    res = my_strdup("zjmp");
  else
    res = get_name_inst2(inst, ct);
  return (res);
}

char	*get_name_inst2(char *inst, int ct)
{
  char	*res;

  if (inst[ct] == 0x0a)
    res = my_strdup("ldi");
  else if (inst[ct] == 0x0b)
    res = my_strdup("sti");
  else if (inst[ct] == 0x0c)
    res = my_strdup("fork");
  else if (inst[ct] == 0x0d)
    res = my_strdup("lld");
  else if (inst[ct] == 0x0e)
    res = my_strdup("lldi");
  else if (inst[ct] == 0x0f)
    res = my_strdup("lfork");
  else if (inst[ct] == 0x10)
    res = my_strdup("aff");
  return (res);
}
