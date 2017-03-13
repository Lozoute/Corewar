/*
** asm_syntax.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Mon Dec  8 12:27:29 2014 florian hellegouarch
** Last update Sun Dec 14 22:48:23 2014 Thibaud Auzou
*/

#include <fcntl.h>
#include <unistd.h>
#include "lib.h"
#include "asm.h"

static int	list_syntax(t_str_list *list)
{
  int		error;

  error = 0 | check_cmd(list);
  error |= check_labels(list);
  error |= check_ops(list);
  return (error ? ERROR : 0);
}

int		asm_syntax(char *file)
{
  t_str_list	*list;
  int		fd;
  int		r;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    {
      my_putstre("Unable to open the file ");
      my_putstre(file);
      my_putstre("\n");
      return (-1);
    }
  list = file_to_list(fd);
  remove_comment(list);
  remove_extra_spaces(list);
  r = list_syntax(list);
  free_list(list);
  close(fd);
  return (r);
}
