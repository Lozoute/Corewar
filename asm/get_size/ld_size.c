/*
** ld_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Tue Dec  9 18:09:02 2014 Thibaud Auzou
** Last update Wed Dec 10 12:48:20 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void		ld_size(t_param *p)
{
  if (p != NULL)
    {
      if (p->param[0] == 'r')
	p->param_size = 1;
      else if (p->param[0] == '%')
	p->param_size = 4;
      else
	p->param_size = 2;
      p = p->next;
      if (p != NULL)
	{
	  p->param_size = 1;
	}
    }
}
