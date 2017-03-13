/*
** set_champs_on_board.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 19:18:33 2014 Thibaud Auzou
** Last update Sun Dec 14 19:55:20 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		set_champs_on_board(t_board *board, t_champ **champs)
{
  int		tab[2][5];
  t_champ	*champ;
  int		tmp;
  int		i;

  i = 0;
  tmp = 0;
  champ = *champs;
  init_tab_pos(tab);
  init_priority(champ, tab);
  while (champ != NULL)
    {
      if (tab[0][i] == -1)
	tab[0][i] = tmp;
      tmp = tmp + champ->size_prog + 500;
      champ->pc = tab[0][i++];
      champ = champ->next;
    }
  fill_tab(tab, *champs);
  if (tmp > MEM_SIZE)
    my_putstre("Total size of champions is too big for memory\n");
  if (tmp > MEM_SIZE)
    return (ERROR);
  fill_board(board, champs, tab);
  return (OK);
}

void	check_tab_pos(int tab[][5], t_champ *champs)
{
  int	ct;

  ct = 0;
  while (champs != NULL && champs->next != NULL)
    {
      if (tab[1][ct] >= tab[0][ct + 1])
	{
	  my_putstre("Not enough memory\n");
	  exit(0);
	}
      ct++;
      champs = champs->next;
    }
}

void		fill_tab(int tab[][5], t_champ *champ)
{
  int		ct;
  t_champ	*tmp;

  tmp = champ;
  ct = 0;
  while (champ != NULL)
    {
      tab[1][ct] = tab[0][ct] + champ->size_prog;
      ct++;
      champ = champ->next;
    }
  check_tab_pos(tab, tmp);
  return ;
}

void	init_tab_pos(int tab[][5])
{
  int	ct;
  int	ct2;

  ct = 0;
  ct2 = 0;
  while (ct < 2)
    {
      while (ct2 < 5)
	{
	  tab[ct][ct2] = -1;
	  ct2++;
	}
      ct++;
      ct2 = 0;
    }
  return ;
}

void	init_priority(t_champ *champ, int tab[][5])
{
  int	i;

  i = 0;
  while (champ != NULL)
    {
      if (champ->options.mem != -1)
	tab[0][i] = champ->options.mem;
      i++;
      champ = champ->next;
    }
  return ;
}
