/*
** size_lldi.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Thu Dec 11 18:20:52 2014 quentin vieira
** Last update Sun Dec 14 20:35:26 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void	size_lldi(char *inst, int ct, int *res)
{
  res[2] = 2;
  res[3] = 2;
  res[4] = 2;
  if (inst[ct] > -1)
    res[4] = 2;
  return ;
}
