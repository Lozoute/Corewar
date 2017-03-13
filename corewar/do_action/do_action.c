/*
** do_action.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 08:19:41 2014 Thibaud Auzou
** Last update Sun Dec 14 19:28:01 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_action(t_board *board,
			  t_champ **champs,
			  t_champ *champ,
			  int (**dof)())
{
  t_inst	*ins;

  ins = board[champ->pc].ins;
  dof[ins->val_ins - 1](board, champs, champ);
  if (ins->val_ins != 9)
    {
      champ->pc = champ->pc + ins->tot_bytes;
    }
  return (OK);
}

int		get_real_value_param(char *tab, int size)
{
  t_swap	u;
  int		i;

  i = 0;
  while (i < 4)
  {
    u.buff[i] = tab[i];
    i++;
  }
  if (size == 1)
    return (u.nb % REG_NUMBER);
  if (size == 4)
    return (my_swap_endian(u.nb));
  u.buff[3] = u.buff[0];
  u.buff[0] = u.buff[1];
  u.buff[1] = u.buff[3];
  u.buff[3] = 0;
  return (u.nb);
}
