/*
** get_size_inst.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/vieira_q/
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Wed Dec 10 18:29:20 2014 quentin vieira
** Last update Sun Dec 14 20:33:36 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "revasm.h"

void	init_tab_size(int *res)
{
  int	ct;

  ct = 0;
  while (ct < 5)
    res[ct++] = 0;
  res[0] = 1;
  res[1] = 1;
  return ;
}

void	print_tab(int *res)
{
  int	ct;

  ct = 0;
  while (ct < 5)
    {
      my_putstr("[");
      my_put_nbr(res[ct]);
      my_putstr("] ");
      ct++;
    }
  return ;
}

void	get_size_inst(char *inst, int ct, int *res, t_ftab *my_ftab)
{
  int	ct2;

  ct2 = 0;
  while (inst[ct] != my_ftab[ct2].hex_val)
    {
      if (ct2 > 15)
	{
	  my_put_error("Unexpected error , program closing\n");
	  exit(0);
	}
      ct2++;
    }
  my_ftab[ct2].f (inst, ct, res);
  return ;
}

int	init_ftab(t_ftab *f)
{
  f[0].hex_val = 0x01;
  f[1].hex_val = 0x02;
  f[2].hex_val = 0x03;
  f[3].hex_val = 0x04;
  f[4].hex_val = 0x05;
  f[5].hex_val = 0x06;
  f[6].hex_val = 0x07;
  f[7].hex_val = 0x08;
  f[8].hex_val = 0x09;
  f[9].hex_val = 0x0a;
  f[10].hex_val = 0x0b;
  f[11].hex_val = 0x0c;
  f[12].hex_val = 0x0d;
  f[13].hex_val = 0x0e;
  f[14].hex_val = 0x0f;
  f[15].hex_val = 0x10;
  init_ftab_func(f);
  return (0);
}

int	init_ftab_func(t_ftab *f)
{
  f[0].f = size_live;
  f[1].f = size_ld;
  f[2].f = size_st;
  f[3].f = size_add;
  f[4].f = size_sub;
  f[5].f = size_and;
  f[6].f = size_and;
  f[7].f = size_and;
  f[8].f = size_zjmp;
  f[9].f = size_ldi;
  f[10].f = size_sti;
  f[11].f = size_fork;
  f[12].f = size_ld;
  f[13].f = size_lldi;
  f[14].f = size_fork;
  f[15].f = size_aff;
  return (0);
}
