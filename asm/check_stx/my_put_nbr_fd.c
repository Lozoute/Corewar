/*
** my_put_nbr_fd.c for corewar in /home/helleg_f/rendu/corewar
** 
** Made by florian hellegouarch
** Login   <helleg_f@epitech.net>
** 
** Started on  Wed Dec 10 15:30:13 2014 florian hellegouarch
** Last update Wed Dec 10 15:55:09 2014 florian hellegouarch
*/

#include <unistd.h>

static void	my_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}

void	my_put_nbr_fd(long nb, int fd)
{
  if (nb < 0)
    {
      my_putchar_fd('-', fd);
      my_put_nbr_fd(-nb, fd);
    }
  else
    {
      if (nb / 10 != 0)
	my_put_nbr_fd(nb / 10, fd);
      my_putchar_fd(nb % 10 + '0', fd);
    }
}
