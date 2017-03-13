/*
** load_options.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 17:58:48 2014 Thibaud Auzou
** Last update Sun Dec 14 00:43:38 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"

int		load_options(t_options options[], char **av)
{
  int		k;
  int		i;
  int		err;

  i = 0;
  k = 0;
  init_options(options);
  while (av != NULL && av[i] != NULL)
    {
      if (my_strcmp(DUMP_STX, av[i]) == 0)
	err = load_dump(options, av[++i]);
      else if (my_strcmp(NUM_STX, av[i]) == 0)
	err = load_num(options, av[++i], k);
      else if (my_strcmp(MEM_STX, av[i]) == 0)
	err = load_mem(options, av[++i], k);
      else
	err = load_name(options, av[i], k++);
      i++;
      if (err == ERROR)
	return (ERROR);
    }
  if (k == 0)
    return (print_not_enough_champ());
  return (update_num(options));
}

int		init_options(t_options options[])
{
  int		i;

  i = 0;
  while (i < MAX_CHAMP)
    {
      options[i].name = NULL;
      options[i].dump = -1;
      options[i].mem = -1;
      options[i].num = -1;
      i++;
    }
  return (OK);
}

int		update_num(t_options options[])
{
  int		i;

  i = 0;
  while (i < MAX_CHAMP)
    {
      if (options[i].num == -1)
	{
	  if ((options[i].num = set_num(options)) == ERROR)
	    return (ERROR);
	}
      i++;
    }
  return (OK);
}

int		set_num(t_options options[])
{
  int		i;
  int		j;
  int		res;

  i = 1;
  while (i <= MAX_CHAMP)
    {
      j = 0;
      res = i;
      while (j < MAX_CHAMP)
	{
	  if (options[j].num == i)
	    res = -1;
	  j++;
	}
      if (res != -1)
	return (res);
      i++;
    }
  return (ERROR);
}
