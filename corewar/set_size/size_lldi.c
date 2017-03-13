/*
** size_lldi.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/set_size
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:06:44 2014 Thibaud Auzou
** Last update Sat Dec 13 18:29:43 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"

void	size_lldi(char *inst, int ct, int *res)
{
  res[2] = 2;
  res[3] = 2;
  res[4] = 2;
  if (inst[ct] > -1)
    res[4] = 2;
  return ;
}
