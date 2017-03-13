/*
** play_corewar.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 07:29:13 2014 Thibaud Auzou
** Last update Sun Dec 14 19:39:52 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		play_corewar(t_board *board, t_champ **champs, int (**dof)())
{
  int		die;
  int		nbr_live;
  int		death;

  death = CYCLE_TO_DIE;
  while (death)
    {
      nbr_live = NBR_LIVE;
      while (nbr_live > 0)
	{
	  die = death;
	  while (die > 0)
	    {
	      do_cycle(board, champs, dof);
	      die--;
	    }
	  if (kill_the_dead(champs) == ERROR)
	    return (OK);
	  nbr_live--;
	  print_state_of_game(board);
	}
      death -= CYCLE_DELTA;
    }
  return (my_putstr("There is no winner\n"));
}

int		print_state_of_game(t_board *board)
{
  print_board(board);
  return (OK);
}

int		do_cycle(t_board *board, t_champ **champs, int (**dof)())
{
  t_champ	*champ;

  champ = *champs;
  while (champ != NULL)
    {
      if (board[champ->pc].ins == NULL)
	champ->pc = (champ->pc + 1) % MEM_SIZE;
      else if (champ->cycle == 0)
	champ->cycle = get_cycle(board[champ->pc].ins);
      else if (champ->cycle == 1)
	do_action(board, champs, champ, dof);
      champ->cycle = champ->cycle - 1;
      champ = champ->next;
    }
  return (OK);
}

int		get_cycle(t_inst *ins)
{
  if (ins == NULL)
    return (0);
  return (op_tab[ins->val_ins - 1].nbr_cycles);
}
