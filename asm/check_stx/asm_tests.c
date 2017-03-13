/*
** asm_tests.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Tue Dec  9 15:42:38 2014 florian hellegouarch
** Last update Sat Dec 13 18:23:08 2014 florian hellegouarch
*/

#include <stdlib.h>
#include "op.h"

char	*is_str_start(char *str, char *str2)
{
  if (!str || !str2)
    return (NULL);
  while (*str && *str == *str2)
    {
      str++;
      str2++;
    }
  if (!*str)
    return (str2);
  return (NULL);
}

int	is_space(char c)
{
  return (c == ' ' || c == '\t');
}

int	is_label_char(char c)
{
  char	*label_chars;

  label_chars = LABEL_CHARS;
  while (*label_chars)
    if (c == *label_chars++)
      return (1);
  return (0);
}

char	*is_label(char *line)
{
  if (is_label_char(*line))
    {
      while (is_label_char(*line))
	line++;
      if (*line == LABEL_CHAR)
	return (line + 1);
    }
  return (NULL);
}
