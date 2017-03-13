/*
** do_lfork.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 04:14:14 2014 quentin vieira
** Last update Sun Dec 14 17:15:27 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_lfork(t_board *board, t_champ **champs, t_champ *champ)
{
  int		pc;
  t_param	*p;
  t_champ	*elem;

  p = board[champ->pc % MEM_SIZE].ins->params;
  pc = get_real_value_param(p->val, p->param_size);
  pc = (champ->pc + pc) % MEM_SIZE;
  if ((elem = malloc(sizeof(t_champ))) == NULL)
    exit(EXIT_FAILURE);
  copy_champ(elem, champ);
  elem->my_inst = copy_ins(champ->my_inst);
  elem->pc = pc;
  add_fork_to_list(champs, elem);
  return (OK);
}
