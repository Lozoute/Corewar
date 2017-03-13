/*
** do_ld.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/do_action
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:02:07 2014 quentin vieira
** Last update Sun Dec 14 17:15:46 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_ld(t_board *board, t_champ **champs, t_champ *champ)
{
  int		nb;
  t_inst	*ins;
  t_param	*p;
  int		reg;

  ins = board[champ->pc].ins;
  if (ins == NULL)
    return (ERROR);
  p = ins->params;
  if (p == NULL)
    return (ERROR);
  nb = get_real_value_param(p->val, p->param_size);
  reg = get_real_value_param(p->next->val, p->next->param_size);
  (champ->carry == 0) ? (champ->carry = 1) : (champ->carry = 0);
  champ->reg[reg - 1] = get_value_ld(board, p, nb, champ);
  return (OK);
}

int		get_value_ld(t_board *board,
			     t_param *p,
			     int nb,
			     t_champ *champ)
{
  int		tmp;

  tmp = (champ->pc + (nb % IDX_MOD)) % MEM_SIZE;
  if (p->param_size == 4)
    return (nb);
  if (p->param_size == 2)
    return (get_value_on_board(board, tmp, 4));
  if (p->param_size == 1)
    nb = champ->reg[nb - 1];
  tmp = (champ->pc + (nb % IDX_MOD)) % MEM_SIZE;
  return (get_value_on_board(board, tmp, 4));
}
