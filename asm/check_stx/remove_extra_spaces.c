/*
** remove_extra_spaces.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Wed Dec 10 10:37:13 2014 florian hellegouarch
** Last update Sun Dec 14 21:25:56 2014 Thibaud Auzou
*/

#include "asm.h"

static void	res_start(char *line)
{
  char		*pt;

  pt = line;
  while (is_space(*pt))
    pt++;
  while (*pt)
    *line++ = *pt++;
  *line = 0;
}

static void	res_end(char *line)
{
  char		*pt;

  while (*line)
    {
      while (*line && !is_space(*line))
	line++;
      pt = line;
      while (*pt && is_space(*pt))
	  pt++;
      if (*pt == 0)
	*line = 0;
      line = pt;
    }
}

static void	res_label(char *line)
{
  char		*pt;

  if ((line = is_label(line)))
    {
      if (is_space(*line))
	{
	  line++;
	  pt = line;
	  while (is_space(*line))
	    line++;
	  while (*line)
	    *pt++ = *line++;
	  *pt = 0;
	}
    }
}

void	res_around_char(char *line, char c)
{
  char	*pt;

  while (*line)
    {
      while (*line && *line != c && !is_space(*line))
	line++;
      if (is_space(*line))
	{
	  pt = line;
	  while (is_space(*pt))
	    pt++;
	  if (*pt == c)
	    res_start(line);
	}
      while (*line && *line != c)
        line++;
      if (*line == c)
	{
          line++;
	  res_start(line);
        }
    }
}

void	remove_extra_spaces(t_str_list *l)
{
  char	*pt;

  while (l)
    {
      res_start(l->str);
      res_end(l->str);
      res_label(l->str);
      pt = l->str;
      while (*pt)
	{
	  if (is_space(*pt))
	    res_start(pt + 1);
	  pt++;
	}
      res_around_char(l->str, SEPARATOR_CHAR);
      l = l->next;
    }
}
