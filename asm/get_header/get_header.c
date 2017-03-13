/*
** get_header.c for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Mon Dec  8 17:36:56 2014 Thibaud Auzou
** Last update Thu Dec 11 15:15:23 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "asm.h"
#include "op.h"

int		get_prog_name(char *name, int fd)
{
  char		*buff;
  int		i;

  init_field_header(name, PROG_NAME_LENGTH + 4);
  if ((buff = get_next_line(fd)) == NULL)
    return (ERROR);
  while (buff[0] != '.' && buff[1] != '.')
    {
      free(buff);
      buff = get_next_line(fd);
      if (buff == NULL)
	return (ERROR);
    }
  i = 0;
  while (buff != NULL && buff[i] != '\0' && buff[i] != '"')
    i++;
  if (buff[i] == '\0')
    return (ERROR);
  name = my_strncpy(name, &(buff[i + 1]), my_strlen(&(buff[i + 1])) - 1);
  free(buff);
  return (OK);
}

int		get_prog_size(t_list **list)
{
  t_list	*tmp;
  int		res;

  res = 0;
  tmp = *list;
  while (tmp != NULL)
    {
      res += tmp->tot_bytes;
      tmp = tmp->next;
    }
  return (my_swap_endian(res));
}

int		get_prog_comment(char *name, int fd)
{
  char		*buff;
  int		i;

  init_field_header(name, COMMENT_LENGTH + 4);
  if ((buff = get_next_line(fd)) == NULL)
    return (ERROR);
  while (buff[0] != '.' && buff[1] != '.')
    {
      free(buff);
      buff = get_next_line(fd);
      if (buff == NULL)
	return (ERROR);
    }
  i = 0;
  while (buff != NULL && buff[i] != '\0' && buff[i] != '"')
    i++;
  if (buff[i] == '\0')
    return (ERROR);
  name = my_strncpy(name, &(buff[i + 1]), my_strlen(&(buff[i + 1])) - 1);
  free(buff);
  return (OK);
}

int		init_field_header(char *str, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      str[i] = 0x00;
      i++;
    }
  return (0);
}
