/*
** size_ld.c for size_ld in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 00:23:45 2014 quentin vieira
** Last update Sun Dec 14 20:34:58 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void			size_ld(char *inst, int ct, int *res)
{
  unsigned char	my_char;

  my_char = inst[ct + 1];
  res[3] = 1;
  if ((my_char >> 6) == 1)
    res[2] = 1;
  else if ((my_char >> 6) == 3)
    res[2] = 2;
  else
    res[2] = 4;
  return ;
}
