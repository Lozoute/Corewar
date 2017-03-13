/*
** print_board.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 01:52:53 2014 Thibaud Auzou
** Last update Sun Dec 14 21:42:21 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int			print_board(t_board *board)
{
  int			i;
  int			j;

  j = 0;
  i = 0;
  while (i < MEM_SIZE)
    {
      my_putstr(fetch_color(board[i].champ));
      my_putstr("[");
      fetch_val(&(board[i]));
      my_putstr("]");
      my_putstr(COLOR_RESET);
      i++;
      j++;
      if (j == 42)
	{
	  j = 0;
	  my_putchar('\n');
	}
    }
  my_putchar('\n');
  return (OK);
}

char			*fetch_color(t_champ *champ)
{
  if (champ == NULL)
    return (NULL);
  if (champ->reg[0] == 1)
    return (COLOR_BLUE);
  if (champ->reg[0] == 2)
    return (COLOR_GREEN);
  if (champ->reg[0] == 3)
    return (COLOR_RED);
  if (champ->reg[0] == 4)
    return (COLOR_YELLOW);
  return (NULL);
}

int			fetch_val(t_board *elem)
{
  if (elem->ins != NULL)
    return (convert_hex(elem->ins->val_ins));
  if (elem->code != 0)
    return (convert_hex(elem->code));
  if (elem->param != NULL)
    return (convert_hex(elem->param->val[elem->param_byte]));
  return (convert_hex(0));
}

int			convert_hex(char c)
{
  char			*hexa;
  char			pre[3];
  unsigned char	tmp;

  tmp = (unsigned char)(c);
  pre[0] = '0';
  pre[1] = '0';
  pre[2] = 0;
  hexa = "0123456789ABCDEF";
  if (tmp > 15)
    {
      pre[1] = hexa[tmp % 16];
      pre[0] = hexa[tmp / 16];
    }
  else
    pre[1] = hexa[(int)(tmp)];
  my_putstr(pre);
  return (0);
}
