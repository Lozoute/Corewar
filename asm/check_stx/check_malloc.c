/*
** check_malloc.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Tue Dec  9 15:02:58 2014 florian hellegouarch
** Last update Sat Dec 13 19:09:45 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include <unistd.h>

static int	cm_strlen(char *str)
{
  int		n;

  n = 0;
  if (str)
    {
      while (*str++)
	n++;
    }
  return (n);
}

static char	*cm_error_str()
{
  return ("Can't perfom malloc\n");
}

void	*check_malloc(int size)
{
  void	*pt;

  if ((pt = malloc(size)) == NULL)
    {
      write(2, cm_error_str(), cm_strlen(cm_error_str()));
      exit(1);
    }
  else
    return (pt);
}
