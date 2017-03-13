/*
** label_syntax.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Tue Dec  9 16:50:21 2014 florian hellegouarch
** Last update Sat Dec 13 20:05:47 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "op.h"
#include "asm.h"

static int	label_len(char *label)
{
  int		n;

  n = 0;
  if (label)
    {
      while (*label && *label != LABEL_CHAR)
	{
	  n++;
	  label++;
	}
    }
  return (n);
}

static char	*get_label(char *line, t_str_list *list, int *error)
{
  char		*label;
  char		*pt;

  if (is_label(line))
    {
      label = check_malloc(label_len(line) + 1);
      pt = label;
      while (*line != LABEL_CHAR)
	*pt++ = *line++;
      *pt = 0;
      if (!*(line + 1) && check_empty_label(list->next))
	{
	  my_putstr(COLOR_RED);
	  my_putstre("label ");
	  my_putstre(label);
	  my_putstre(" empty\n");
	  my_putstr(COLOR_RESET);
	  *error = 1;
	}
      return (label);
    }
  return (NULL);
}

static int	check_new_label(t_str_list *list, char *label)
{
  while (list)
    {
      if (!my_strcmp(list->str, label))
	{
	  my_putstr(COLOR_RED);
	  my_putstre("label ");
	  my_putstre(label);
	  my_putstre(" defined more than once\n");
	  my_putstr(COLOR_RESET);
	  return (1);
	}
      list = list->next;
    }
  return (0);
}

t_str_list	*get_label_list(t_str_list *lines, int *error)
{
  t_str_list	*labels;
  char		*line;
  char		*label;
  int		err;

  err = 0;
  labels = NULL;
  *error = 0;
  while (lines)
    {
      line = lines->str;
      while (is_space(*line))
	line++;
      if ((label = get_label(line, lines, &err)) != NULL)
	{
	  err |= check_new_label(labels, label);
	  if (!err)
	    add_to_list(&labels, label);
	  else
	    free(label);
	  *error |= err;
	}
      lines = lines->next;
    }
  return (labels);
}

int		check_labels(t_str_list *lines)
{
  t_str_list	*labels;
  int		error;

  labels = get_label_list(lines, &error);
  error |= check_labels_def(lines, labels);
  free_list(labels);
  return (error);
}
