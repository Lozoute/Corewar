##
## Makefile for corewar in /home/auzou_t/CPE_2014_corewar/corewar
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Sat Dec 13 17:48:15 2014 Thibaud Auzou
## Last update Sun Dec 14 21:20:33 2014 Thibaud Auzou
##

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wextra -Wall -Wno-unused-parameter
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I../include/ -I../../include/

LDFLAGS	= -lmy -L../lib/

NAME		= corewar

SRCS		= main.c \
		  misc/op.c \
		  list/list_champ.c \
		  list/list_inst.c \
		  init/init_game.c \
		  init/init_inst.c \
		  set_size/get_size_inst.c \
		  msg_options/msg_options.c \
		  load_options/load_options.c \
		  load_options/load_functions.c \
		  set_size/size_live.c \
		  set_size/size_ld.c \
		  set_size/size_st.c \
		  set_size/size_add.c \
		  set_size/size_sub.c \
		  set_size/size_and.c \
		  set_size/size_zjmp.c \
		  set_size/size_ldi.c \
		  set_size/size_fork.c \
		  set_size/size_lldi.c \
		  set_size/size_aff.c \
		  set_size/size_sti.c \
		  list/list_param.c \
		  place_champions/fill_board.c \
		  place_champions/set_champs_on_board.c \
		  print/print_board.c \
		  delete/delete.c \
		  delete/free.c \
		  do_action/play_corewar.c \
		  do_action/do_action.c \
		  do_action/do_live.c \
		  do_action/do_ld.c \
		  do_action/do_st.c \
		  do_action/do_add.c \
		  do_action/do_sub.c \
		  do_action/do_and.c \
		  do_action/do_or.c \
		  do_action/do_xor.c \
		  do_action/do_zjmp.c \
		  do_action/do_ldi.c \
		  do_action/do_sti.c \
		  do_action/do_fork.c \
		  do_action/do_lld.c \
		  do_action/do_lldi.c \
		  do_action/do_lfork.c \
		  do_action/do_aff.c

OBJS		= $(SRCS:.c=.o)

MAKELIB	= make -C ../lib/

CLEANLIB	= make clean -C ../lib/

FCLEANLIB	= make fclean -C ../lib/


all: $(NAME)

$(NAME): $(OBJS)
		$(MAKELIB)
		$(CC) $(OBJS) -o $(NAME) $(LIB) $(LDFLAGS)

clean:
		$(CLEANLIB)
		$(RM) $(OBJS)

fclean: clean
		$(FCLEANLIB)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
