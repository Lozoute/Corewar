##
## Makefile for corewar in /home/auzou_t/CPE_2014_corewar/revasm
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Sun Dec 14 20:06:55 2014 Thibaud Auzou
## Last update Sun Dec 14 21:21:22 2014 Thibaud Auzou
##

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wextra -Wall -Werror
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I../include/ -I../../include/

LDFLAGS	= -lmy -L../lib/

NAME		= revasm

SRCS		= src/main.c \
		  op.c \
		  src/list/list_champ.c \
		  src/list/list_inst.c \
		  src/init_game.c \
		  src/init_inst.c \
		  src/get_size_inst.c \
		  src/my_messages.c \
		  src/set_size/size_live.c \
		  src/set_size/size_ld.c \
		  src/set_size/size_st.c \
		  src/set_size/size_add.c \
		  src/set_size/size_sub.c \
		  src/set_size/size_and.c \
		  src/set_size/size_zjmp.c \
		  src/set_size/size_ldi.c \
		  src/set_size/size_fork.c \
		  src/set_size/size_lldi.c \
		  src/set_size/size_aff.c \
		  src/set_size/size_sti.c \
		  src/list/list_param.c

OBJS		= $(SRCS:.c=.o)

MAKELIB	= make -C ../lib/

CLEANLIB	= make clean -C ../lib/

FCLEANLIB	= make fclean -C ../lib/


all: 		$(NAME)

$(NAME): 	$(OBJS)
		$(MAKELIB)
		$(CC) $(OBJS) -o $(NAME) $(LIB) $(LDFLAGS)

clean:
		$(RM) $(OBJS)
		$(CLEANLIB)

fclean: 	clean
		$(RM) $(NAME)
		$(FCLEANLIB)

re:  fclean all

.PHONY: all  clean fclean re
