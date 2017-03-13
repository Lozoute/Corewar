/*
** my_strcpy.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:02:22 2014 Thibaud Auzou
** Last update Sat Dec  6 19:02:35 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  if (dest == NULL || src == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
