/*
** load_functions.c for corewar in /home/auzou_t/CPE_2014_corewar/load_options
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:00:11 2014 Thibaud Auzou
** Last update Sun Dec 14 05:23:40 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"
#include "lib.h"

int		load_dump(t_options options[], char *str)
{
  int		nb;
  int		i;

  nb = my_getnbr(str);
  if (nb < 1 || str == NULL)
    {
      my_putstre("Wrong dump value\n");
      return (ERROR);
    }
  i = 0;
  while (i < MAX_CHAMP)
    {
      if (options[i].dump != -1)
	{
	  my_putstre("Dump value already set\n");
	  return (ERROR);
	}
      options[i].dump = nb;
      i++;
    }
  return (OK);
}

int		load_num(t_options options[], char *str, int k)
{
  int		i;
  int		nb;

  if ((nb = my_getnbr(str)) < 1 || nb > MAX_CHAMP || str == NULL)
    {
      my_putstre("Wrong champion number\n");
      return (ERROR);
    }
  i = 0;
  while (i <= k)
    {
      if (options[i].num == nb || options[k].num != -1)
	{
	  my_putstre("This champion number is already taken or already set\n");
	  return (ERROR);
	}
      i++;
    }
  options[k].num = nb;
  return (OK);
}

int		load_mem(t_options options[], char *str, int k)
{
  int		i;
  int		nb;

  if ((nb = my_getnbr(str)) < 0 || str == NULL)
    {
      my_putstre("Wrong memory location\n");
      return (ERROR);
    }
  i = 0;
  while (i <= k)
    {
      if (options[i].mem == nb || options[k].mem != -1)
	{
	  my_putstre("This memory location is already taken\n");
	  return (ERROR);
	}
      i++;
    }
  options[k].mem = nb % MEM_SIZE;
  return (OK);
}

int		load_name(t_options options[], char *str, int k)
{
  int		i;

  if (k == MAX_CHAMP)
    return (print_too_much_champ());
  if (str != NULL && str[0] == '-')
    return (print_wrong_option(str));
  i = 0;
  while (i < k)
    {
      if (my_strcmp(options[i].name, str) == 0 || options[k].name != NULL)
	{
	  my_putstre("You can set a champion only once\n");
	  return (ERROR);
	}
      i++;
    }
  options[k].name = str;
  return (OK);
}
