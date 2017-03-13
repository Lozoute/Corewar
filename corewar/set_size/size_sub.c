/*
** size_sub.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/set_size
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:07:37 2014 Thibaud Auzou
** Last update Sat Dec 13 18:29:52 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"

void	size_sub(char *inst, int ct, int *res)
{
  res[2] = 1;
  res[3] = 1;
  res[4] = 1;
  if (inst[ct + 1] > -1)
    res[4] = 1;
  return ;
}
