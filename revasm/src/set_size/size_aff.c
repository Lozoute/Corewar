/*
** size_aff.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 18:25:28 2014 quentin vieira
** Last update Sun Dec 14 20:34:39 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void	size_aff(char *inst, int ct, int *res)
{
  res[2] = 1;
    if (inst[ct] > -1)
      res[2] = 1;
  return ;
}
