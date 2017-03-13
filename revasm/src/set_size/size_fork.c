/*
** size_fork.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 18:09:00 2014 quentin vieira
** Last update Sun Dec 14 20:34:50 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void	size_fork(char *inst, int ct, int *res)
{
  res[1] = 0;
  res[2] = 2;
  if (inst[ct + 1] > -100)
    res[2] = 2;
  return ;
}
