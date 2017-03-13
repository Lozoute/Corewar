/*
** my_str_to_wordtab.c for corewar in /home/auzou_t/CPE_2014_corewar/lib
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Mon Dec  8 22:21:22 2014 Thibaud Auzou
** Last update Tue Dec  9 18:04:51 2014 Thibaud Auzou
*/

#include <stdlib.h>
#include "lib.h"

void	free_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      free(tab[i]);
      tab[i] = NULL;
      i++;
    }
  if (tab != NULL)
    free(tab);
}

char	*allocate_string(char *str, int nb, int *indice)
{
  char	*str_add;
  int	i;

  str_add = NULL;
  str_add = malloc((nb + 1) * sizeof(char));
  if (str_add == NULL)
    return (NULL);
  i = 0;
  while (i < nb)
    {
      if (str[i] != '\n')
	str_add[i] = str[i];
      i = i + 1;
    }
  str_add[i] = '\0';
  (str[i] == '\0') ? (*indice = nb) : (*indice = nb + 1);
  return (str_add);
}

int	find_sep(char *str, int *indice)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != ';' && str[i] != '#' &&
	 (str[i] == ' ' || str[i] == '\t' || str[i] == ','))
    i = i + 1;
  if (str[i] == '\0' || str[i] == ';' || str[i] == '#')
    return (-1);
  *indice = i;
  while (str[i] != '\0' && str[i] != ';' && str[i] != '#' &&
	 str[i] != ' ' && str[i] != '\t' && str[i] != ',')
    i = i + 1;
  return (i - (*indice));
}

int	count_words(char *str, int *nb, int i)
{
  if (str == NULL)
    return (0);
  while (str[i] != '\0' && str[i] != ';' && str[i] != '#' &&
	 (str[i] == ' ' || str[i] == '\t' || str[i] == ','))
    i = i + 1;
  if (str[i] == '\0' || str[i] == ';' || str[i] == '#')
    return (0);
  while (str[i] != '\0' && str[i] !=  ';' && str[i] != '#' &&
	 str[i] != ' ' && str[i] != '\t' && str[i] != ',')
    i = i + 1;
  *nb = *nb + 1;
  if (str[i] != '\0' || str[i] != ';' || str[i] != '#')
    count_words(&(str[i]), nb, 0);
  return (0);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	tab_size;
  int	nb;
  int	j;

  tab = NULL;
  tab_size = 0;
  count_words(str, &tab_size, 0);
  if (tab_size == 0 || str == NULL)
    return (tab);
  if ((tab = malloc((tab_size + 1) * sizeof(char *))) == NULL)
    return (NULL);
  tab[tab_size] = NULL;
  j = 0;
  i = 0;
  while (j < tab_size && (nb = find_sep(str, &i)) != -1)
    {
      str = &(str[i]);
      if ((tab[j] = allocate_string(str, nb, &i)) == NULL)
	return (NULL);
      j = j + 1;
      str = str + i;
    }
  return (tab);
}
