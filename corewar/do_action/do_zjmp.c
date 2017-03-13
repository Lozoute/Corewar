/*
** do_zjmp.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:08:57 2014 quentin vieira
** Last update Sun Dec 14 19:14:21 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_zjmp(t_board *board, t_champ **champs, t_champ *champ)
{
  int		nb;
  t_param	*p;

  if (champ->carry == 1)
    {
      p = board[champ->pc % MEM_SIZE].ins->params;
      nb = get_real_value_param(p->val, p->param_size);
      champ->pc = (champ->pc + (nb % IDX_MOD)) % MEM_SIZE;
    }
  return (OK);
}
