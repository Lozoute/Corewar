/*
** size_st.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 17:19:57 2014 quentin vieira
** Last update Sun Dec 14 20:35:31 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void			size_st(char *inst, int ct, int *res)
{
  unsigned char	my_char;

  res[2] = 1;
  my_char = inst[ct + 1];
  my_char = my_char << 2;
  my_char = my_char >> 6;
  if (my_char == 1)
    res[3] = 1;
  else if (my_char == 3)
    res[3] = 2;
  else if (my_char == 2)
    res[3] = 2;
  return ;
}
