/*
** size_live.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/set_size
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:06:26 2014 Thibaud Auzou
** Last update Sat Dec 13 18:30:08 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"

void	size_live(char *inst, int ct, int *res)
{
  res[1] = 0;
  res[2] = 4;
  if (inst[ct] >= 0)
    res[2] = 4;
  return ;
}
