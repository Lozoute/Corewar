##
## Makefile for libmy in /home/auzou_t/CPE_2014_corewar/lib
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Sat Dec  6 19:06:14 2014 Thibaud Auzou
## Last update Sun Dec 14 20:51:33 2014 Thibaud Auzou
##

CC	= gcc

AR	= ar rc

NAME	= libmy.a

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I../include/

SRC	= my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_strcpy.c \
	  my_strncpy.c \
	  my_strcat.c \
	  my_putstre.c \
	  my_strncmp.c \
	  my_strcmp.c \
	  my_strdup.c \
	  my_strndup.c \
	  my_getnbr.c \
	  get_next_line.c \
	  my_swap_endian.c \
	  my_str_to_wordtab.c \
	  my_put_nbr_fd.c \
	  my_put_error.c \
	  my_putstr_fd.c

OBJS	= $(SRC:.c=.o)

RM	= rm -f


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
