/*
** sti_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 12:50:48 2014 Thibaud Auzou
** Last update Wed Dec 10 18:30:18 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void		sti_size(t_param *p)
{
  if (p != NULL)
    {
      if (p->param[0] == 'r')
	p->param_size = 1;
      else
	p->param_size = 2;
      sti_size(p->next);
    }
}
