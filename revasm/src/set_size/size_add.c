/*
** size_add.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 17:25:15 2014 quentin vieira
** Last update Sun Dec 14 20:34:34 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void	size_add(char *inst, int ct, int *res)
{
  res[2] = 1;
  res[3] = 1;
  res[4] = 1;
  if (inst[ct + 1] > -1)
    res[4] = 1;
  return ;
}
