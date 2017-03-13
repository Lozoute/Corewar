/*
** main.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 17:49:51 2014 Thibaud Auzou
** Last update Sun Dec 14 19:28:18 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		main(int argc, char **argv)
{
  t_champ	*champs;
  t_options	options[MAX_CHAMP];
  t_board	board[MEM_SIZE];
  int		(*dof[NB_INS])();

  if (argc < 2 || argv == NULL || *argv == NULL)
    {
      my_print_usage();
      return (ERROR);
    }
  if (load_options(options, &(argv[1])) == ERROR)
    return (ERROR);
  if ((champs = init_game(options)) == NULL)
    return (ERROR);
  init_board(board);
  if (set_champs_on_board(board, &champs) == ERROR)
    return (ERROR);
  init_dof(dof);
  print_board(board);
  return (play_corewar(board, &champs, dof));
}

int		init_dof(int (**dof)())
{
  dof[0] = do_live;
  dof[1] = do_ld;
  dof[2] = do_st;
  dof[3] = do_add;
  dof[4] = do_sub;
  dof[5] = do_and;
  dof[6] = do_or;
  dof[7] = do_xor;
  dof[8] = do_zjmp;
  dof[9] = do_ldi;
  dof[10] = do_sti;
  dof[11] = do_fork;
  dof[12] = do_lld;
  dof[13] = do_lldi;
  dof[14] = do_lfork;
  dof[15] = do_aff;
  return (OK);
}

int		init_board(t_board *board)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      board[i].champ = NULL;
      board[i].ins = NULL;
      board[i].code = 0;
      board[i].param = NULL;
      i++;
    }
  return (OK);
}
