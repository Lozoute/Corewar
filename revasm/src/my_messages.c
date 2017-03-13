/*
** my_messages.c for corewar in /home/montre_n/CPE_2014_corewar/nicolas
**
** Made by nicolas montredon
** Login   <montre_n@epitech.net>
**
** Started on  Sun Dec  7 15:52:50 2014 nicolas montredon
** Last update Sun Dec 14 20:52:08 2014 Thibaud Auzou
*/

#include "revasm.h"

int			my_print_usage()
{
  my_put_error("Usage : ./revasm file1.cor file2.cor file3.cor ...\n");
  return (0);
}
