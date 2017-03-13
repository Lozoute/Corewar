/*
** size_live.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/vieira_q/src/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 00:16:48 2014 quentin vieira
** Last update Sun Dec 14 20:35:20 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void	size_live(char *inst, int ct, int *res)
{
  res[1] = 0;
  res[2] = 4;
  if (inst[ct] >= 0)
    res[2] = 4;
  return ;
}
