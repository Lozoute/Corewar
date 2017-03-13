/*
** my_putchar.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 18:59:24 2014 Thibaud Auzou
** Last update Sat Dec  6 18:59:42 2014 Thibaud Auzou
*/

#include <unistd.h>
#include "lib.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}
