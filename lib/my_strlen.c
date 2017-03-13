/*
** my_strlen.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:03:06 2014 Thibaud Auzou
** Last update Sat Dec  6 19:03:16 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
