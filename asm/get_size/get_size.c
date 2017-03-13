/*
** get_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Tue Dec  9 14:36:22 2014 Thibaud Auzou
** Last update Wed Dec 10 12:56:47 2014 Thibaud Auzou
*/

#include "lib.h"
#include "op.h"
#include "asm.h"

int		get_params_size(t_list *elem)
{
  t_f_tab	f[NB_INS];
  int		i;

  init_f(f);
  i = 0;
  while (i < NB_INS)
    {
      if (my_strcmp(f[i].name, elem->ins) == 0)
	f[i].f(elem->params);
      i++;
    }
  return (0);
}

int		init_f(t_f_tab *f)
{
  int		i;

  i = 0;
  while (i < 16)
    {
      f[i].name = op_tab[i].mnemonique;
      i++;
    }
  init_f_function(f);
  return (0);
}

int		init_f_function(t_f_tab *f)
{
  f[0].f = live_size;
  f[1].f = ld_size;
  f[2].f = st_size;
  f[3].f = add_size;
  f[4].f = sub_size;
  f[5].f = and_size;
  f[6].f = and_size;
  f[7].f = and_size;
  f[8].f = zjmp_size;
  f[9].f = ldi_size;
  f[10].f = sti_size;
  f[11].f = fork_size;
  f[12].f = lld_size;
  f[13].f = lldi_size;
  f[14].f = lfork_size;
  f[15].f = aff_size;
  return (0);
}
