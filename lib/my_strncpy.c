/*
** my_strncpy.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:03:46 2014 Thibaud Auzou
** Last update Sat Dec  6 19:03:53 2014 Thibaud Auzou
*/

#include "lib.h"

char		*my_strncpy(char *dest, char *src, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
