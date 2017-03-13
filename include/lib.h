/*
** lib.h for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Dec 10 19:49:06 2014 Thibaud Auzou
** Last update Sun Dec 14 20:49:45 2014 Thibaud Auzou
*/

#ifndef LIB_H_
# define LIB_H_

# define NB_INS	16
# define READ_SIZE	512
# define ERROR		-1
# define OK		0
# define COLOR_GREEN	"\x1b[1;32;40m"
# define COLOR_YELLOW	"\x1b[1;33;40m"
# define COLOR_RED	"\x1b[1;31;40m"
# define COLOR_RESET	"\x1b[0m"
# define COLOR_BLUE	"\x1b[1;34;40m"

typedef union		u_swap
{
  char			buff[4];
  int			nb;
}			t_swap;

/*
** Get Next Line
*/
char			*get_next_line(const int fd);
int			len(char *str);
int			add_to_save(char *buff);
int			remove_from_save(int *ok, int i);
char			*cut_save(int *ok, int force_cutting, int i, int j);

/*
** Basic Lib
*/
int			my_putchar(char c);
int			my_putstr(char *str);
int			my_putstre(char *str);
int			my_strlen(char *str);
int			my_put_nbr(int nb);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int nb);
char			*my_strcpy(char *s1, char *s2);
char			*my_strncpy(char *s1, char *s2, int nb);
char			*my_strcat(char *dest, char *src);
char			*my_strdup(char *src);
char			*my_strndup(char *src, int nb);
char			**my_str_to_wordtab(char *str);
int			my_swap_endian(int nb);
void			free_wordtab(char **tab);
int			my_getnbr(char *str);
void			my_put_nbr_fd(long nb, int fd);
int			my_put_error(char *str);
void			my_putstr_fd(char *str, int fd);

#endif /* !LIB_H_ */
