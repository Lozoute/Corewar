/*
** delete.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 11:29:38 2014 Thibaud Auzou
** Last update Sun Dec 14 19:34:13 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		kill_the_dead(t_champ **champs)
{
  t_champ	*tmp;
  t_champ	*tmp2;

  tmp = *champs;
  if (there_is_a_winner(champs))
    return (ERROR);
  while (tmp != NULL)
    {
      tmp2 = tmp->next;
      if (tmp->alive == 0)
	delete_champ(champs, tmp);
      else
	print_alive(tmp);
      tmp = tmp2;
    }
  my_putchar('\n');
  init_new_cycle(champs);
  return (OK);
}

int		print_alive(t_champ *tmp)
{
  my_putstr(fetch_color(tmp));
  my_putstr(tmp->champ_name);
  my_putstr(" (n° ");
  my_put_nbr(tmp->reg[0]);
  my_putstr(") is alive !\n");
  my_putstr(COLOR_RESET);
  return (OK);
}

int		init_new_cycle(t_champ **champs)
{
  t_champ	*tmp;

  tmp = *champs;
  while (tmp != NULL)
    {
      tmp->alive = 0;
      tmp = tmp->next;
    }
  return (OK);
}

int		there_is_a_winner(t_champ **champs)
{
  t_champ	*tmp;
  int		num;

  tmp = *champs;
  if (tmp == NULL)
    {
      my_putstr("Nobody wins, everyone's dead\n");
      return (1);
    }
  num = tmp->reg[0];
  while (tmp != NULL)
    {
      if (tmp->reg[0] != num)
	return (0);
      tmp = tmp->next;
    }
  tmp = *champs;
  my_putstr(fetch_color(tmp));
  my_putstr(tmp->champ_name);
  my_putstr(" (n° ");
  my_put_nbr(tmp->reg[0]);
  my_putstr(") has won !\n");
  my_putstr(COLOR_RESET);
  return (1);
}

int		delete_champ(t_champ **champs, t_champ *tmp)
{
  if (tmp->prev != NULL)
    tmp->prev->next = tmp->next;
  if (tmp->next != NULL)
    tmp->next->prev = tmp->prev;
  if (tmp->prev == NULL)
    *champs = tmp->next;
  free_champ(tmp);
  tmp = NULL;
  return (OK);
}
