/*
** size_st.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/set_size
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:07:02 2014 Thibaud Auzou
** Last update Sun Dec 14 21:42:49 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"

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
