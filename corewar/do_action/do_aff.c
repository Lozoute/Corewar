/*
** do_aff.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:14:46 2014 quentin vieira
** Last update Sun Dec 14 17:17:28 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_aff(t_board *board, t_champ **champs, t_champ *champ)
{
  t_param	*p;
  int		reg;

  p = board[champ->pc % MEM_SIZE].ins->params;
  reg = get_real_value_param(p->val, p->param_size);
  my_putchar(champ->reg[reg - 1] % 256);
  return (OK);
}
