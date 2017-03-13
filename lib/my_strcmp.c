/*
** my_strcmp.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:01:56 2014 Thibaud Auzou
** Last update Sat Dec  6 19:02:06 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      if (s2[i] == '\0')
	return (1);
      i = i + 1;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}
