/*
** cmd_syntax.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Wed Dec 10 16:37:14 2014 florian hellegouarch
** Last update Sun Dec 14 21:22:03 2014 Thibaud Auzou
*/

#include "asm.h"
#include "lib.h"

static int	is_cmd_valid(char *line)
{
  int		r;

  r = -1;
  if (is_name(line))
    r = 0;
  else if (is_comment(line))
    r = 1;
  if (r != -1)
    {
      while (*line && !is_space(*line))
	line++;
      line++;
      if (line[0] == '"'
	      && line[1] == '"'
	      && line[2] == 0)
	return (r);
      cmd_error(r == 0 ? "name" : "comment");
      return (-1);
    }
  return (2);
}

void	cmd_err(int n, char *cmd)
{
  my_putstr(COLOR_RED);
  if (n == 0)
    {
      my_putstre(cmd);
      my_putstre(" undefined\n");
    }
  else if (n > 1)
    {
      my_putstre(cmd);
      my_putstre(" defined more than once\n");
    }
  my_putstr(COLOR_RESET);
}

int	check_extend(t_str_list *lines)
{
  while (lines)
    {
      if (is_extend(lines->str))
	{
	  my_putstr(COLOR_RED);
	  my_putstre(".extend not implemented\n");
	  my_putstr(COLOR_RESET);
	  return (1);
	}
      lines = lines->next;
    }
  return (0);
}

int	check_cmd(t_str_list *lines)
{
  int	error;
  int	r;
  int	cmd[2];
  int	extend;

  cmd[0] = cmd[1] = 0;
  error = 0;
  extend = check_extend(lines);
  while (lines)
    {
      r = is_cmd_valid(lines->str);
      if (lines->str[0] && !is_extend(lines->str)
	  && !is_name(lines->str) && !is_comment(lines->str))
	break;
      if (r == -1)
	error = 1;
      else if (r < 2)
	cmd[r]++;
      lines = lines->next;
    }
  cmd_err(cmd[0], "name");
  cmd_err(cmd[1], "comment");
  return (error || extend
	  || cmd[0] != 1 || cmd[1] != 1);
}
