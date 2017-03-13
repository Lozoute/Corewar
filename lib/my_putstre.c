/*
** my_putstre.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:01:00 2014 Thibaud Auzou
** Last update Sat Dec  6 19:01:07 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

int	my_putstre(char *str)
{
  if (str == NULL)
    return (0);
  if (write(2, str, my_strlen(str)) == -1)
    return (1);
  return (0);
}
