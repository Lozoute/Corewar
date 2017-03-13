/*
** my_strndup.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:04:04 2014 Thibaud Auzou
** Last update Mon Dec  8 22:27:38 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"

char		*my_strndup(char *src, int nb)
{
  char		*str;

  if (src == NULL)
    return (NULL);
  str = NULL;
  if ((str = malloc(sizeof(char) * (nb + 1))) == NULL)
    return (NULL);
  str = my_strncpy(str, src, nb);
  return (str);
}
