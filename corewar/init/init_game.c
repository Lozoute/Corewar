/*
** init_game.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/init
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 17:54:18 2014 Thibaud Auzou
** Last update Sun Dec 14 21:38:50 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "init.h"
#include "lib.h"

t_champ	*init_game(t_options *options)
{
  t_champ	*my_champs;

  my_champs = NULL;
  if ((my_champs = create_list(options, my_champs)) == NULL )
    {
      my_putstre("Error : while creating champions list\n");
      return (NULL);
    }
  else if ((my_champs = init_inst(my_champs)) == NULL)
    {
      my_putstre("Error : while creating instructions list\n");
      return (NULL);
    }
  return (my_champs);
}

t_champ	*create_list(t_options *options, t_champ *my_champs)
{
  int		ct;
  int		my_fd;
  int		size_inst;
  char		*my_name;
  char		*comm;

  ct = 0;
  while (ct < MAX_CHAMP && options[ct].name != NULL)
    {
      if ((my_fd = get_fd(options[ct].name)) == -1)
	return (NULL);
      if ((my_name = get_name(options[ct].name, my_fd)) == NULL)
	return (NULL);
      if ((size_inst = get_size_prog(options[ct].name, my_fd)) == -1)
	return (NULL);
      if ((comm = get_comment(options[ct].name, my_fd)) == NULL)
	return (NULL);
      if (add_champ_to_list(my_name, my_fd, &my_champs) == -1)
	return (NULL);
      my_champs = add_elem_to_champ(my_champs, comm, size_inst, options[ct]);
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
      my_putstre(my_file);
      my_putstre(" : could not read comment\n");
      return (NULL);
    }
  buff[COMMENT_LENGTH + 1] = '\0';
  if ((res = my_strdup(buff)) == NULL)
    {
      my_putstre("Could not malloc\n");
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
      my_putstre(my_file);
      my_putstre(" : could not read name\n");
      return (NULL);
    }
  buff[PROG_NAME_LENGTH + 1] = '\0';
  if ((res = my_strdup(buff)) == NULL)
    {
      my_putstre("Could not malloc\n");
      return (NULL);
    }
  return (res);
}

int		get_fd(char *my_file)
{
  int		fd;
  int		my_nb;

  fd = open(my_file, O_RDWR);
  if (fd == -1)
    {
      my_putstre("Could not open ");
      my_putstre(my_file);
      my_putstre("\n");
      return (-1);
    }
  if (read (fd, &my_nb, 4) <= 0)
    {
      my_putstre("Could not read header\n");
      return (-1);
    }
  my_nb = my_swap_endian(my_nb);
  if (my_nb != COREWAR_EXEC_MAGIC)
    {
      my_putstre(my_file);
      my_putstre(" is not a cor file\n");
      return (-1);
    }
  return (fd);
}
