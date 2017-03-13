/*
** init_inst.c for  in /home/vieira_q/Prog_elem_C/CPE_2014_corewar/vieira_q
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Tue Dec  9 17:52:07 2014 quentin vieira
** Last update Sun Dec 14 20:33:43 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "revasm.h"

t_champ		*init_inst(t_champ *my_list)
{
  t_champ	*tmp;
  t_inst	*my_inst;

  tmp = my_list;
  my_inst = NULL;
  while (my_list != NULL)
    {
      if ((my_inst = get_inst(my_list)) == NULL)
	{
	  my_put_error("Error : while reading instructions in ");
	  my_put_error(my_list->champ_name);
	  my_put_error("\n");
	  return (NULL);
	}
      my_list->my_inst = my_inst;
      my_list = my_list->next;
    }
  return (tmp);
}

t_inst		*get_inst(t_champ *my_list)
{
  t_inst	*my_res;
  char		*buff_inst;
  int		ct;
  int		size[5];
  t_ftab	my_ftab[16];

  my_res = NULL;
  ct = 0;
  init_ftab(my_ftab);
  if ((buff_inst = get_all_inst(my_list)) == NULL)
    return (NULL);
  while (ct < my_list->size_prog)
    {
      init_tab_size(size);
      get_size_inst(buff_inst, ct, size, my_ftab);
      if (add_ins_to_list(&my_res, size, buff_inst, ct) == -1)
	{
	  my_put_error("Could not malloc\n");
	  return (NULL);
	}
      ct = ct + size[0] + size[1] + size[2] + size[3] + size[4];
    }
  set_linst_to_first(my_res);
  return (my_res);
}

char	*get_all_inst(t_champ *my_list)
{
  char	*buff;

  if ((buff = malloc((my_list->size_prog + 1) * sizeof(char))) == NULL)
    {
      my_put_error("Could not malloc\n");
      return (NULL);
    }
  if (read(my_list->champ_fd, buff, my_list->size_prog) <= 0)
    {
      my_put_error(" could not read instructions from ");
      my_put_error(my_list->champ_name);
      my_put_error("\n");
      return (NULL);
    }
  buff[my_list->size_prog] = '\0';
  return (buff);
}

int	get_size_prog(char *my_file, int fd)
{
  int	res;

  if (read(fd, &res, sizeof(int)) <= 0)
    {
      my_put_error(my_file);
      my_put_error(" : could not read size\n");
      return (-1);
    }
  res = my_swap_endian(res);
  return (res);
}
