/*
** asm.c for corewar in /home/auzou_t/CPE_2014_corewar/asm
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 18:37:50 2014 Thibaud Auzou
** Last update Sun Dec 14 22:12:39 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "lib.h"
#include "asm.h"
#include "op.h"

int		main(int argc, char **argv)
{
  int		fd;
  int		i;

  i = 1;
  if (argc < 2 || argv == NULL || *argv == NULL)
    {
      my_putstre("Usage: \"./asm file_name[.s]\"\n");
      return (ERROR);
    }
  while (argv != NULL && argv[i] != NULL)
    {
      if (asm_syntax(argv[i]) == ERROR)
	return (ERROR);
      if ((fd = open(argv[i], O_RDONLY)) == -1)
	return (ERROR);
      if (build_binary_file(fd, get_champ_name(argv[i])) == ERROR)
	return (ERROR);
      fd = close(fd);
      i++;
    }
  return ((fd == -1) ? (ERROR) : (OK));
}

char		*get_champ_name(char *str)
{
  char		*name;
  int		size;

  size = 0;
  while (str[size] != '\0' && str[size] != '.')
    size++;
  if ((name = malloc(size + 5)) == NULL)
    {
      my_putstre("Can't perform malloc\n");
      exit(EXIT_FAILURE);
    }
  name = my_strncpy(name, str, size);
  name = my_strcat(name, ".cor");
  return (name);
}

int		build_binary_file(int fd, char *name)
{
  header_t	h;

  if (my_strncmp(name, "/dev/urandom", my_strlen("/dev/urandom")) == 0)
    return (ERROR);
  h.magic = my_swap_endian(COREWAR_EXEC_MAGIC);
  if (get_prog_name(h.prog_name, fd) == ERROR)
    return (ERROR);
  if (get_prog_comment(h.comment, fd) == ERROR)
    return (ERROR);
  return (build_content(fd, name, &h));
}

int		build_content(int fd, char *name, header_t *h)
{
  int		fd2;
  t_list	*list;
  int		param;

  list = NULL;
  if (get_content(&list, fd) == ERROR)
    return (ERROR);
  h->prog_size = get_prog_size(&list);
  param = O_WRONLY | O_CREAT | O_TRUNC;
  if ((fd2 = open(name, param, S_IRUSR | S_IWUSR)) == -1)
    return (ERROR);
  if (write(fd2, h, sizeof(header_t)) == -1)
    return (ERROR);
  if (write_content(&list, fd2) == ERROR)
    return (ERROR);
  my_putstr(COLOR_GREEN);
  my_putstr(name);
  my_putstr(" successfuly assembled\n");
  my_putstr(COLOR_RESET);
  free(name);
  close(fd2);
  return (OK);
}
