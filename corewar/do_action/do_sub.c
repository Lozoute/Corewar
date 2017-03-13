/*
** do_sub.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:07:20 2014 quentin vieira
** Last update Sun Dec 14 17:22:42 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_sub(t_board *board, t_champ **champs, t_champ *champ)
{
  int		reg1;
  int		reg2;
  int		reg3;
  t_param	*p;

  p = board[champ->pc].ins->params;
  reg1 = get_real_value_param(p->val, p->param_size);
  reg2 = get_real_value_param(p->next->val, p->next->param_size);
  reg3 = get_real_value_param(p->next->next->val, p->next->next->param_size);
  champ->reg[reg3] = champ->reg[reg1] - champ->reg[reg2];
  (champ->carry == 0) ? (champ->carry = 1) : (champ->carry = 0);
  return (OK);
}
