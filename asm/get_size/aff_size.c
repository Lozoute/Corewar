/*
** aff_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 12:56:14 2014 Thibaud Auzou
** Last update Wed Dec 10 12:56:39 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void		aff_size(t_param *p)
{
  if (p != NULL)
    {
      p->param_size = 1;
    }
}
