/*
** do_and.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:07:42 2014 quentin vieira
** Last update Sun Dec 14 17:16:28 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_and(t_board *board, t_champ **champs, t_champ *champ)
{
  t_param	*p;
  int		p1;
  int		p2;
  int		reg;

  p = board[champ->pc % MEM_SIZE].ins->params;
  reg = get_real_value_param(p->next->next->val, p->next->next->param_size);
  p1 = get_value_p(board, p, champ);
  p2 = get_value_p(board, p->next, champ);
  champ->reg[reg - 1] = p1 & p2;
  (champ->carry == 0) ? (champ->carry = 1) : (champ->carry = 0);
  return (OK);
}

int		get_value_p(t_board *board, t_param *p, t_champ *champ)
{
  int		ind;

  if (p->param_size == 4)
    return (get_real_value_param(p->val, p->param_size));
  if (p->param_size == 2)
    {
      ind = get_real_value_param(p->val, p->param_size) % MEM_SIZE;
      return (get_value_on_board(board, ind, 4));
    }
  else
    return (champ->reg[get_real_value_param(p->val, p->param_size) - 1]);
}
