/*
** main.c for main in /home/vieira_q/Prog_elem_C/Corewar/vm
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec  7 17:00:37 2014 quentin vieira
** Last update Sun Dec 14 20:42:00 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "revasm.h"
#include "corewar.h"

int		main(int argc, char **argv)
{
  t_champ	*my_champs;
  int		ct;

  ct = 1;
  if (argc < 2 || argv == NULL || *argv == NULL)
    {
      my_print_usage();
      return (-1);
    }
  if ((my_champs = init_game(argc, argv)) == NULL)
    return (-1);
  while (ct < argc)
    {
      if (init_new_fd(my_champs, argv[ct]) == ERROR)
	{
	  my_put_error("Error while creating file");
	  return (-1);
	}
      if (my_champs->next != NULL)
	my_champs = my_champs->next;
      ct++;
    }
  my_champs = set_list_to_first(my_champs);
  print_champ_list(&my_champs);
  return (0);
}

int	init_new_fd(t_champ *my_champ, char *name)
{
  char	*new_name;
  int	param;

  if ((new_name = get_new_name(name)) == NULL)
    {
      my_put_error("Error while trying to generate new file name\n");
      return (ERROR);
    }
  param = O_WRONLY | O_CREAT | O_TRUNC;
  if ((my_champ->champ_fd = open(new_name, param, S_IRUSR | S_IWUSR)) == ERROR)
    {
      my_put_error("Could not create or open file\n");
      return (ERROR);
    }
  return (0);
}

char	*get_new_name(char *name)
{
  char	*res;
  int	ct;

  ct = my_strlen(name);
  if (name[ct - 1] != 'r'
      || name[ct - 2] != 'o'
      || name[ct - 3] != 'c'
      || name[ct - 4] != '.')
    return (NULL);
  else
    {
      if ((res = malloc(my_strlen(name) - 1)) == NULL)
	return (NULL);
      ct = 0;
      while (ct < my_strlen(name) - 3)
	{
	  res[ct] = name[ct];
	  ct++;
	}
    }
  res[ct] = 's';
  res[ct + 1] = '\0';
  return (res);
}
