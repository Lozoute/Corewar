/*
** cmd_syntax2.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Wed Dec 10 17:15:37 2014 florian hellegouarch
** Last update Sat Dec 13 19:13:59 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "asm.h"
#include "lib.h"

void	cmd_error(char *str)
{
  my_putstre("invalid ");
  my_putstre(str);
  my_putstre("\n");
}

int	is_name(char *line)
{
  return (is_str_start(NAME_CMD_STRING, line) != NULL);
}

int	is_comment(char *line)
{
  return (is_str_start(COMMENT_CMD_STRING, line) != NULL);
}

int	is_extend(char *line)
{
  return (is_str_start(".extend", line) != NULL);
}

int	is_cmd(char *line)
{
  return (is_name(line)
	  || is_comment(line)
	  || is_extend(line));
}
