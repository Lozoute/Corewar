/*
** size_and.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 17:36:12 2014 quentin vieira
** Last update Sun Dec 14 20:34:45 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void			size_and(char *inst, int ct, int *res)
{
  unsigned char	my_char;

  my_char = inst[ct + 1];
  res[4] = 1;
  if ((my_char >> 6) == 1)
    res[2] = 1;
  else if ((my_char >> 6) == 3)
    res[2] = 2;
  else
    res[2] = 4;
  my_char = my_char << 2;
  if ((my_char  >> 6) == 1)
    res[3] = 1;
  else  if ((my_char  >> 6) == 3)
    res[3] = 2;
  else
    res[3] = 4;
  return ;
}
