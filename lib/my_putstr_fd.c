/*
** my_putstr_fd.c for corewar in /home/auzou_t/CPE_2014_corewar/revasm
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 20:50:15 2014 Thibaud Auzou
** Last update Sun Dec 14 20:51:14 2014 Thibaud Auzou
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

void		my_putstr_fd(char *str, int fd)
{
  if (str != NULL)
    {
      write(fd, str, my_strlen(str));
    }
}
