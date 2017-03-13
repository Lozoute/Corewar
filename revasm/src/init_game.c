/*
** init_game.c for init_game in /home/vieira_q/Prog_elem_C/Corewar/vm
** 
** Made by quentin vieira
** Login   <vieira_q@epitech.net>
** 
** Started on  Sun Dec  7 23:51:55 2014 quentin vieira
** Last update Sun Dec 14 20:33:27 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "revasm.h"
#include "corewar.h"

t_champ		*init_game(int argc, char **argv)
{
  t_champ	*my_champs;

  my_champs = NULL;
  if ((my_champs = create_list(argc, argv, my_champs))== NULL )
    {
      my_put_error("Error : while creating champions list\n");
      return (NULL);
    }
  else if ((my_champs = init_inst(my_champs))== NULL)
    {
      my_put_error("Error : while creating instructions list\n");
      return (NULL);
    }
  return (my_champs);
}

t_champ		*create_list(int argc,  char **argv, t_champ *my_champs)
{
  int		ct;
  int		my_fd;
  int		size_inst;
  char		*my_name;
  char		*comm;

  ct = 1;
  while (argv != NULL && ct < argc)
    {
      if ((my_fd = get_fd(argv[ct])) == -1)
	return (NULL);
      if ((my_name = get_name(argv[ct], my_fd)) == NULL)
	return (NULL);
      if ((size_inst = get_size_prog(argv[ct], my_fd)) == -1)
	return (NULL);
      if ((comm = get_comment(argv[ct], my_fd)) == NULL)
	return (NULL);
      if (add_champ_to_list(my_name, my_fd, &my_champs) == -1)
	return (NULL);
      my_champs = add_elem_to_champ(my_champs, comm, size_inst);
      ct++;
    }
  my_champs = set_list_to_first(my_champs);
  return (my_champs);
}

char	*get_comment(char *my_file, int fd)
{
  char	buff[COMMENT_LENGTH + 4];
  char	*res;

  if (read(fd, buff, COMMENT_LENGTH + 4) <= 0)
    {
      my_put_error(my_file);
      my_put_error(" : could not read comment\n");
      return (NULL);
    }
  buff[COMMENT_LENGTH + 1] = '\0';
  if ((res = my_strdup(buff)) == NULL)
    {
      my_put_error("Could not malloc\n");
      return (NULL);
    }
  return (res);
}

char	*get_name(char *my_file, int fd)
{
  char	buff[PROG_NAME_LENGTH + 4];
  char	*res;

  if (read(fd, buff, PROG_NAME_LENGTH + 4) <= 0)
    {
      my_put_error(my_file);
      my_put_error(" : could not read name\n");
      return (NULL);
    }
  buff[PROG_NAME_LENGTH + 1] = '\0';
  if ((res = my_strdup(buff)) == NULL)
    {
      my_put_error("Could not malloc\n");
      return (NULL);
    }
  return (res);
}

int	get_fd(char *my_file)
{
  int	fd;
  int	my_nb;

  fd = open(my_file, O_RDWR);
  if (fd == -1)
    {
      my_put_error("Could not open ");
      my_put_error(my_file);
      my_put_error("\n");
      return (-1);
    }
  if (read (fd, &my_nb, 4) <= 0)
    {
      my_put_error("Could not read header\n");
      return (-1);
    }
  my_nb = my_swap_endian(my_nb);
  if (my_nb != COREWAR_EXEC_MAGIC)
    {
      my_put_error(my_file);
      my_put_error(" is not a cor file\n");
      return (-1);
    }
  return (fd);
}
