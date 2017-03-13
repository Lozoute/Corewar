/*
** my_put_error.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 20:26:54 2014 Thibaud Auzou
** Last update Sun Dec 14 20:28:09 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

int		my_put_error(char *str)
{
  if (str == NULL)
    return (-1);
  if (write(2, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}
