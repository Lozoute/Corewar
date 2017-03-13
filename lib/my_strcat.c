/*
** my_strcat.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:01:20 2014 Thibaud Auzou
** Last update Sat Dec  6 19:01:28 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  if (dest == NULL || src == NULL)
    return (NULL);
  i = my_strlen(dest);
  j = 0;
  while (src[j])
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
