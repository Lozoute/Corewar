/*
** size_zjmp.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 17:58:48 2014 quentin vieira
** Last update Sun Dec 14 20:35:48 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void	size_zjmp(char *inst, int ct, int *res)
{
  res[1] = 0;
  res[2] = 2;
  if (inst[ct] > -1)
    res[2] = 2;
  return ;
}
