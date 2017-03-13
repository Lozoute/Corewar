/*
** do_ldi.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:09:24 2014 quentin vieira
** Last update Sun Dec 14 19:46:01 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_ldi(t_board *board, t_champ **champs, t_champ *champ)
{
  int		p1;
  int		p2;
  int		reg;
  t_param	*p;
  int		ind;
  int		a;

  p = board[champ->pc % MEM_SIZE].ins->params;
  p1 = get_value_ldi(p, champ);
  p2 = get_value_ldi(p->next, champ);
  a = p->next->next->param_size;
  reg = get_real_value_param(p->next->next->val, a) % 15;
  ind = (champ->pc + (p1 % IDX_MOD)) % MEM_SIZE;
  p1 = get_value_on_board(board, ind, 2) + p2;
  ind = (champ->pc + (p1 % IDX_MOD)) % MEM_SIZE;
  champ->reg[reg - 1] = get_value_on_board(board, ind, 4);
  (champ->carry == 0) ? (champ->carry = 1) : (champ->carry = 0);
  return (OK);
}

int		get_value_ldi(t_param *p, t_champ *champ)
{
  if (p->param_size == 1)
    return (champ->reg[get_real_value_param(p->val, p->param_size)]);
  return (get_real_value_param(p->val, p->param_size));
}
