/*
** op_syntax.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Wed Dec 10 18:20:31 2014 florian hellegouarch
** Last update Sat Dec 13 19:58:22 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"
#include "asm.h"
#include "op.h"

static op_t	*get_op(char **line)
{
  int		i;
  char		*pt;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      pt = is_str_start(op_tab[i].mnemonique, *line);
      if (pt && !is_label_char(*pt))
	{
	  while (**line && !is_space(**line))
	    (*line)++;
	  while (is_space(**line))
	    (*line)++;
	  return (&(op_tab[i]));
	}
      i++;
    }
  return (NULL);
}

static int	check_op(char *line, int nb_line)
{
  op_t		*op;

  op = get_op(&line);
  if (op)
    return (check_params(op, line, nb_line));
  else
    {
      my_putstr(COLOR_RED);
      my_putstre("Syntax error line ");
      my_put_nbr_fd(nb_line, 2);
      my_putstre("\n");
      my_putstr(COLOR_RESET);
      return (1);
    }
}

static int	check_op_label(char *line, int nb_line)
{
  char		*pt;

  if ((pt = is_label(line)))
    line = pt;
  while (is_space(*line))
    line++;
  if (*line)
    return (check_op(line, nb_line));
  return (0);
}

int	check_ops(t_str_list *lines)
{
  int	error;
  int	nb_line;

  error = 0;
  nb_line = 1;
  while (lines && (!lines->str[0] || is_cmd(lines->str)))
    {
      nb_line++;
      lines = lines->next;
    }
  while (lines)
    {
      if (lines->str[0])
	error |= check_op_label(lines->str, nb_line);
      lines = lines->next;
      nb_line++;
    }
  return (error);
}
