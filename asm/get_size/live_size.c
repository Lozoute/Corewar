/*
** live_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Tue Dec  9 17:54:08 2014 Thibaud Auzou
** Last update Tue Dec  9 18:16:15 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void		live_size(t_param *p)
{
  if (p != NULL)
    {
      p->param_size = 4;
    }
}
