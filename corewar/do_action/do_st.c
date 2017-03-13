/*
** do_st.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/do_action
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:06:32 2014 quentin vieira
** Last update Sun Dec 14 17:22:14 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_st(t_board *board, t_champ **champs, t_champ *champ)
{
  int		reg;
  int		nb;
  t_inst	*ins;
  t_param	*p;
  int		ind;
  t_swap	u;

  ins = board[champ->pc].ins;
  p = ins->params;
  reg = get_real_value_param(p->val, p->param_size);
  nb = get_real_value_param(p->next->val, p->next->param_size);
  ind = (champ->pc + (nb % IDX_MOD)) % MEM_SIZE;
  u.nb = my_swap_endian(champ->reg[reg - 1]);
  if (p->next->param_size == 1)
    champ->reg[nb - 1] = champ->reg[reg - 1];
  else
    set_value_on_board(board, ind, u.buff, 4);
  return (OK);
}
