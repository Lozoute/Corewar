/*
** lldi_size.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 12:54:28 2014 Thibaud Auzou
** Last update Fri Dec 12 15:53:04 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

void		lldi_size(t_param *p)
{
  if (p != NULL)
    {
      if (p->param[0] == 'r')
	p->param_size = 1;
      else
	p->param_size = 2;
      lldi_size(p->next);
    }
}
