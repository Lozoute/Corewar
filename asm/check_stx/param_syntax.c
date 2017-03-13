/*
** param_syntax.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Wed Dec 10 19:14:14 2014 florian hellegouarch
** Last update Sat Dec 13 22:22:48 2014 quentin vieira
*/

#include "lib.h"
#include "asm.h"
#include "op.h"

static void	next_param(char **line)
{
  while (**line && **line != SEPARATOR_CHAR)
    (*line)++;
  if (**line == SEPARATOR_CHAR)
    (*line)++;
}

static int	check_param(op_t *op, char *param, int i, int nb_line)
{
  if (param[0] == 'r')
    {
      if (op->type[i] & T_REG)
	return (check_param_reg(param, nb_line));
    }
  else if (param[0] == DIRECT_CHAR)
    {
      if (op->type[i] & T_DIR)
	return (check_param_dir(param, nb_line));
    }
  else
    {
      if (op->type[i] & T_IND)
	return (check_param_ind(param, nb_line));
    }
  my_putstr(COLOR_RED);
  my_putstre("invalid parameter ");
  my_put_nbr_fd(i + 1, 2);
  my_putstre(" line ");
  my_put_nbr_fd(nb_line, 2);
  my_putstre("\n");
  my_putstr(COLOR_RESET);
  return (1);
}

void	error_param_num(char *op, char *err, int nb_line)
{
  my_putstr(COLOR_RED);
  my_putstre(op);
  my_putstre(" has to ");
  my_putstre(err);
  my_putstre(" parameters line ");
  my_put_nbr_fd(nb_line, 2);
  my_putstre("\n");
  my_putstr(COLOR_RESET);
}

int	check_params(op_t *op, char *line, int nb_line)
{
  int	i;
  int	error;

  i = 0;
  error = 0;
  op = op;
  while (*line)
    {
      if (i >= op->nbr_args)
	{
	  error_param_num(op->mnemonique, "many", nb_line);
	  return (1);
	}
      error |= check_param(op, line, i, nb_line);
      next_param(&line);
      i++;
    }
  if (i < op->nbr_args)
    {
      error_param_num(op->mnemonique, "few", nb_line);
      return (1);
    }
  return (error);
}
