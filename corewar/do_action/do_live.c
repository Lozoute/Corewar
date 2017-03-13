/*
** do_live.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec 14 03:58:49 2014 quentin vieira
** Last update Sun Dec 14 17:23:25 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		do_live(t_board *board, t_champ **champs, t_champ *champ)
{
  t_champ	*tmp;

  tmp = *champs;
  if (champ == NULL)
    return (ERROR);
  while (tmp != NULL)
    {
      if (tmp->reg[0] == champ->reg[0])
	tmp->alive = 1;
      tmp = tmp->next;
    }
  return (OK);
}

int		get_value_on_board(t_board *board, int ind, int nb)
{
  t_swap	u;
  int		i;
  int		tmp;

  i = 0;
  while (i < 4)
    u.buff[i++] = 0;
  i = 0;
  while (nb > 0)
    {
      tmp = ind % MEM_SIZE;
      if (board[tmp].ins != NULL)
	u.buff[i] = board[tmp].ins->val_ins;
      else if (board[tmp].code != 0)
	u.buff[i] = board[tmp].code;
      else if (board[tmp].param != NULL)
	u.buff[i] = board[tmp].param->val[board[tmp].param_byte];
      else
	u.buff[i] = 0;
      i++;
      ind++;
      nb--;
    }
  return (u.nb);
}

int		set_value_on_board(t_board *board, int ind, char *buff, int nb)
{
  int		i;

  i = 0;
  while (nb > 0)
    {
      board[ind % MEM_SIZE].code = buff[i];
      nb--;
      ind++;
      i++;
    }
  return (OK);
}
