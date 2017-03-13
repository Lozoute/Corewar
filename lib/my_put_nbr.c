/*
** my_put_nbr.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:00:13 2014 Thibaud Auzou
** Last update Wed Dec 10 20:03:39 2014 nicolas montredon
*/

#include "lib.h"

int	size_int(int nb)
{
  int	i;

  i = 1;
  nb = nb / 10;
  while (nb != 0)
    {
      nb = nb / 10;
      i = i * 10;
    }
  return (i);
}

int	display_int(unsigned int nb)
{
  int	i;
  int	div;

  div = size_int(nb);
  while (div != 0)
    {
      i = nb / div;
      nb = nb % div;
      if (my_putchar(i + 48))
	return (1);
      div = div / 10;
    }
  return (0);
}

int	my_put_nbr(int nb)
{
  if (nb == 0)
    return (my_putchar('0'));
  else if (nb < 0)
    {
      if (my_putchar('-'))
	return (1);
      if (display_int(nb * -1))
	return (1);
    }
  else
    {
      if (display_int(nb))
	return (1);
    }
  return (0);
}
