/*
** st_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 12:38:05 2014 Thibaud Auzou
** Last update Wed Dec 10 19:05:54 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void		st_size(t_param *p)
{
  if (p != NULL)
    {
      p->param_size = 1;
      if (p->next != NULL)
	{
	  if (p->next->param[0] == 'r')
	    p->next->param_size = 1;
	  else
	    p->next->param_size = 2;
	}
    }
}
