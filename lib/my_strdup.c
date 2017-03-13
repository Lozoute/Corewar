/*
** my_strdup.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:02:48 2014 Thibaud Auzou
** Last update Mon Dec  8 22:27:21 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"

char	*my_strdup(char *src)
{
  int	size;
  char	*str;

  if (src == NULL)
    return (NULL);
  size = my_strlen(src);
  str = NULL;
  if ((str = malloc(size + 1)) == NULL)
    return (NULL);
  str = my_strcpy(str, src);
  return (str);
}
