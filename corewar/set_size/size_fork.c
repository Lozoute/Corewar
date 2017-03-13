/*
** size_fork.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/set_size
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:05:20 2014 Thibaud Auzou
** Last update Sat Dec 13 18:30:42 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"

void	size_fork(char *inst, int ct, int *res)
{
  res[1] = 0;
  res[2] = 2;
  if (inst[ct + 1] > -100)
    res[2] = 2;
  return ;
}
