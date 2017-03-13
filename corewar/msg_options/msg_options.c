/*
** msg_options.c for corewar in /home/auzou_t/CPE_2014_corewar/corewar/
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:03:12 2014 Thibaud Auzou
** Last update Sat Dec 13 20:12:07 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "op.h"
#include "init.h"
#include "lib.h"

int			my_print_usage()
{
  int			nbchar;

  nbchar = 0;
  nbchar = my_putstre("Usage : ./corwar [-dump nbr_cycle] [[-n prog_number]");
  nbchar = nbchar + my_putstre("[-a load_adress] prog_name] ...\n");
  return (nbchar);
}

int		print_too_much_champ(void)
{
  my_putstre("Too much champions selected [MAX: ");
  my_put_nbr(MAX_CHAMP);
  my_putstre("]\n");
  return (ERROR);
}

int		print_not_enough_champ(void)
{
  my_putstre("You have to set at least 1 champion\n");
  return (ERROR);
}

int		print_wrong_option(char *str)
{
  my_putstre(str);
  my_putstre(": Invalid option\n");
  return (ERROR);
}
