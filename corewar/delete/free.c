/*
** free.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 11:58:50 2014 Thibaud Auzou
** Last update Sun Dec 14 19:47:57 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "init.h"
#include "corewar.h"

int		free_champ(t_champ *champ)
{
  t_inst	*ins;
  t_inst	*tmp;

  free(champ->champ_name);
  free(champ->comment);
  ins = champ->my_inst;
  while (ins != NULL)
    {
      tmp = ins->next;
      free_ins(ins);
      ins = tmp;
    }
  free(champ);
  return (OK);
}

int		free_ins(t_inst *ins)
{
  t_param	*p;
  t_param	*tmp;

  free(ins->ins);
  p = ins->params;
  while (p != NULL)
    {
      tmp = p->next;
      if (p->param != NULL)
	free(p->param);
      free(p);
      p = tmp;
    }
  free(ins);
  return (OK);
}
