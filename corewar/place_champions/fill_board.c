/*
** fill_board.c for corewar in /home/auzou_t/CPE_2014_corewar/nicolas/jeu
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 03:46:37 2014 Thibaud Auzou
** Last update Sun Dec 14 21:41:50 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

void			fill_board(t_board *board,
				   t_champ **champs,
				   int tab[2][5])
{
  t_champ		*champ;
  int			i;

  i = 0;
  champ = *champs;
  while (champ != NULL)
    {
      fill_board_with_champ(board, champ, tab[0][i]);
      i++;
      champ = champ->next;
    }
}

void			fill_board_with_champ(t_board *board,
					      t_champ *champ,
					      int i)
{
  t_inst		*ins;
  t_param		*p;
  int			size;

  ins = champ->my_inst;
  while (ins != NULL)
    {
      board[i].champ = champ;
      board[i].ins = ins;
      board[i].code = 0;
      board[i].param = NULL;
      board[i].param_byte = -1;
      p = ins->params;
      if (ins->code_byte != 0)
	fill_board_with_code(board, ins->code_byte, ++i, champ);
      while (p != NULL)
	{
	  size = p->param_size;
	  while (size > 0)
	    fill_board_with_param(&(board[++i]), p, champ, size--);
	  p = p->next;
	}
      i++;
      ins = ins->next;
    }
}

void			fill_board_with_code(t_board *board,
					     char code,
					     int i,
					     t_champ *champ)
{
  board[i].champ = champ;
  board[i].ins = NULL;
  board[i].code = code;
  board[i].param = NULL;
  board[i].param_byte = -1;
}

void			fill_board_with_param(t_board *board,
					      t_param *p,
					      t_champ *champ,
					      int size)
{
  board->champ = champ;
  board->ins = NULL;
  board->code = 0;
  board->param = p;
  board->param_byte = p->param_size - size;
}
