/*
** param_syntax2.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Thu Dec 11 19:02:27 2014 florian hellegouarch
** Last update Sat Dec 13 20:06:21 2014 Thibaud Auzou
*/

#include "lib.h"
#include "asm.h"
#include "op.h"

static int	get_param_nb(char *param, long *nb, long nb_line)
{
  long		l;
  int		neg;

  l = 0;
  neg = (*param == '-');
  if (neg)
    param++;
  while (*param >= '0' && *param <= '9')
    {
      *nb = l;
      l = l * 10 + *param++ - '0';
      if (*nb != l / 10)
	break;
    }
  if (*nb != l / 10 || (*param && *param != SEPARATOR_CHAR))
    {
      my_putstr(COLOR_RED);
      my_putstre("Invalid number line ");
      my_put_nbr_fd(nb_line, 2);
      my_putstre("\n");
      my_putstr(COLOR_RESET);
      return (1);
    }
  *nb = neg ? -l : l;
  return (0);
}

static int	param_label(char *param, int nb_line)
{
  if (*param == LABEL_CHAR)
    {
      param++;
      while (is_label_char(*param))
	param++;
      if (!(*param) || *param == SEPARATOR_CHAR)
	return (1);
      my_putstr(COLOR_RED);
      my_putstre("Invalid label line ");
      my_put_nbr_fd(nb_line, 2);
      my_putstre("\n");
      my_putstr(COLOR_RESET);
      return (-1);
    }
  return (0);
}

int	check_param_reg(char *param, int nb_line)
{
  long	reg_num;

  param++;
  if (get_param_nb(param, &reg_num, nb_line))
    return (1);
  if (reg_num <= 0 || reg_num > REG_NUMBER)
    {
      my_putstr(COLOR_RED);
      my_putstre("no such register (");
      my_put_nbr_fd(reg_num, 2);
      my_putstre(") line ");
      my_put_nbr_fd(nb_line, 2);
      my_putstre("\n");
      my_putstr(COLOR_RESET);
      return (1);
    }
  return (0);
}

int	check_param_dir(char *param, int nb_line)
{
  int	label;
  long	n;

  param++;
  label = param_label(param, nb_line);
  if (label)
    return (label == 1 ? 0 : 1);
  if (get_param_nb(param, &n, nb_line))
    return (1);
  if (n > 2147483647 || n < -2147483648)
    {
      my_putstr(COLOR_YELLOW);
      my_putstre("Warning Direct too big (");
      my_put_nbr_fd(n, 2);
      my_putstre(") line ");
      my_put_nbr_fd(nb_line, 2);
      my_putstre("\n");
      my_putstr(COLOR_RESET);
    }
  return (0);
}

int	check_param_ind(char *param, int nb_line)
{
  int	label;
  long	n;

  label = param_label(param, nb_line);
  if (label)
    return (label == 1 ? 0 : 1);
  if (get_param_nb(param, &n, nb_line))
    return (1);
  if (n > 32767 || n < -32768)
    {
      my_putstr(COLOR_YELLOW);
      my_putstre("Warning Indirection to far (");
      my_put_nbr_fd(n, 2);
      my_putstre(") line ");
      my_put_nbr_fd(nb_line, 2);
      my_putstre("\n");
      my_putstr(COLOR_RESET);
    }
  return (0);
}
