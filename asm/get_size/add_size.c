/*
** add_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 12:40:34 2014 Thibaud Auzou
** Last update Wed Dec 10 12:42:00 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void		add_size(t_param *p)
{
  if (p != NULL)
    {
      p->param_size = 1;
      if (p->next != NULL)
	p->next->param_size = 1;
      if (p->next != NULL && p->next->next != NULL)
	p->next->next->param_size = 1;
    }
}
