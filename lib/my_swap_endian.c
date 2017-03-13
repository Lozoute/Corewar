/*
** my_swap_endian.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Mon Dec  8 20:24:35 2014 Thibaud Auzou
** Last update Mon Dec  8 22:42:46 2014 Thibaud Auzou
*/

#include "lib.h"

int		my_swap_endian(int nb)
{
  t_swap	u;
  char		c;

  u.nb = nb;
  c = u.buff[0];
  u.buff[0] = u.buff[3];
  u.buff[3] = c;
  c = u.buff[2];
  u.buff[2] = u.buff[1];
  u.buff[1] = c;
  return (u.nb);
}
