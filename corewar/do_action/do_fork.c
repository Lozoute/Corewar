/*
** do_fork.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:10:11 2014 quentin vieira
** Last update Sun Dec 14 18:56:55 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_fork(t_board *board, t_champ **champs, t_champ *champ)
{
  int		pc;
  t_param	*p;
  t_champ	*elem;

  p = board[champ->pc % MEM_SIZE].ins->params;
  pc = get_real_value_param(p->val, p->param_size);
  pc = (champ->pc + (pc % IDX_MOD)) % MEM_SIZE;
  if ((elem = malloc(sizeof(t_champ))) == NULL)
    exit(EXIT_FAILURE);
  copy_champ(elem, champ);
  elem->my_inst = copy_ins(champ->my_inst);
  elem->pc = pc;
  add_fork_to_list(champs, elem);
  return (OK);
}

int		copy_champ(t_champ *dest, t_champ *src)
{
  int		i;

  i = 0;
  dest->champ_name = my_strdup(src->champ_name);
  dest->champ_fd = src->champ_fd;
  dest->size_prog = src->size_prog;
  dest->comment = my_strdup(src->comment);
  dest->carry = src->carry;
  dest->alive = src->alive;
  dest->cycle = 0;
  while (i < REG_NUMBER)
    {
      dest->reg[i] = src->reg[i];
      i++;
    }
  return (0);
}

t_inst		*copy_ins(t_inst *src)
{
  t_inst	*elem;
  t_inst	*tmp;

  elem = NULL;
  while (src != NULL)
    {
      tmp = elem;
      if ((elem = malloc(sizeof(t_inst))) == NULL)
	exit(EXIT_FAILURE);
      elem->ins = my_strdup(src->ins);
      elem->val_ins = src->val_ins;
      elem->params = copy_params(src->params);
      elem->tot_bytes = src->tot_bytes;
      elem->code_byte = src->code_byte;
      elem->prev = tmp;
      elem->next = NULL;
      if (tmp != NULL)
	tmp->next = elem;
      src = src->next;
    }
  while (elem != NULL && elem->prev != NULL)
    elem = elem->prev;
  return (elem);
}

t_param	*copy_params(t_param *src)
{
  t_param	*elem;
  t_param	*tmp;
  int		i;

  elem = NULL;
  while (src != NULL)
    {
      tmp = elem;
      if ((elem = malloc(sizeof(t_param))) == NULL)
	exit(EXIT_FAILURE);
      elem->param_size = src->param_size;
      elem->param = NULL;
      i = -1;
      while (++i < 4)
	elem->val[i] = src->val[i];
      elem->prev = tmp;
      elem->next = NULL;
      if (tmp != NULL)
	tmp->next = elem;
      src = src->next;
    }
  while (elem != NULL && elem->prev != NULL)
    elem = elem->prev;
  return (elem);
}

int		add_fork_to_list(t_champ **champs, t_champ *elem)
{
  t_champ	*tmp;

  tmp = *champs;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  elem->prev = tmp;
  elem->next = NULL;
  if (tmp == NULL)
    *champs = elem;
  else
    tmp->next = elem;
  return (OK);
}
