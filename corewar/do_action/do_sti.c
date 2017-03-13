/*
** do_sti.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:09:48 2014 quentin vieira
** Last update Sun Dec 14 17:14:27 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_sti(t_board *board, t_champ **champs, t_champ *champ)
{
  int		reg;
  int		p2;
  int		p3;
  t_param	*p;
  t_swap	u;
  int		ind;

  p = board[champ->pc % MEM_SIZE].ins->params;
  reg = get_real_value_param(p->val, p->param_size);
  u.nb = champ->reg[reg - 1];
  u.nb = my_swap_endian(u.nb);
  p2 = get_value_ldi(p->next, champ);
  p3 =  get_value_ldi(p->next->next, champ);
  ind = (champ->pc + ((p2 + p3) % IDX_MOD)) % MEM_SIZE;
  set_value_on_board(board, ind, u.buff, 4);
  return (OK);
}
