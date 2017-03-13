/*
** label_syntax2.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Wed Dec 10 14:58:53 2014 florian hellegouarch
** Last update Sat Dec 13 20:08:56 2014 Thibaud Auzou
*/

#include <unistd.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

static int	is_label_in_list(char *label_pt, t_str_list *list, int nb_line)
{
  while (list)
    {
      if (is_str_start(list->str, label_pt))
	return (0);
      list = list->next;
    }
  my_putstr(COLOR_RED);
  my_putstre("label ");
  while (is_label_char(*label_pt))
    {
      write(2, label_pt, 1);
      label_pt++;
    }
  my_putstre(" undefined line ");
  my_put_nbr_fd(nb_line, 2);
  my_putstre("\n");
  my_putstr(COLOR_RESET);
  return (1);
}

static int	check_labels_line(char *line, t_str_list *labels, int nb_line)
{
  int		error;

  error = 0;
  while (*line && !is_space(*line))
    line++;
  while (*line)
    {
      if (*line == LABEL_CHAR)
	error |= is_label_in_list(line + 1, labels, nb_line);
      line++;
    }
  return (error);
}

int	check_labels_def(t_str_list *lines, t_str_list *labels)
{
  int	nb_line;
  int	error;

  nb_line = 1;
  error = 0;
  while (lines)
    {
      error |= check_labels_line(lines->str, labels, nb_line);
      nb_line++;
      lines = lines->next;
    }
  return (error);
}

int	check_empty_label(t_str_list *list)
{
  while (list)
    {
      if (is_label(list->str))
	return (1);
      if (*(list->str))
	return (0);
      list = list->next;
    }
  return (1);
}
