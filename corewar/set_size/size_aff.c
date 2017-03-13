/*
** size_aff.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/set_size
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:04:41 2014 Thibaud Auzou
** Last update Sat Dec 13 18:29:26 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"

void	size_aff(char *inst, int ct, int *res)
{
  res[2] = 1;
    if (inst[ct] > -1)
      res[2] = 1;
  return ;
}
