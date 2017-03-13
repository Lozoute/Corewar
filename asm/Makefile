##
## Makefile for corewar in /home/auzou_t/CPE_2014_corewar/asm
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Sun Dec 14 20:11:32 2014 Thibaud Auzou
## Last update Sun Dec 14 20:11:36 2014 Thibaud Auzou
##

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wextra -Wall -Werror
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I./include/ -I../include/ -D_BSD_SOURCE

LDFLAGS	= -lmy -L../lib/

NAME		= asm

SRCS		= main.c \
		  misc/op.c \
		  get_header/get_header.c \
		  get_content/get_content.c \
		  get_content/fill_list_elem.c \
		  get_size/get_size.c \
		  get_size/live_size.c \
		  get_size/ld_size.c \
		  get_size/st_size.c \
		  get_size/add_size.c \
		  get_size/sub_size.c \
		  get_size/and_size.c \
		  get_size/zjmp_size.c \
		  get_size/ldi_size.c \
		  get_size/sti_size.c \
		  get_size/fork_size.c \
		  get_size/lld_size.c \
		  get_size/lldi_size.c \
		  get_size/lfork_size.c \
		  get_size/aff_size.c \
		  write_content/write_content.c \
		  write_content/get_param_value.c\
		  check_stx/asm_syntax.c \
		  check_stx/asm_tests.c \
		  check_stx/check_malloc.c \
		  check_stx/cmd_syntax2.c \
		  check_stx/cmd_syntax.c \
		  check_stx/label_syntax2.c \
		  check_stx/label_syntax.c \
		  check_stx/op_syntax.c \
		  check_stx/param_syntax2.c \
		  check_stx/param_syntax.c \
		  check_stx/remove_comment.c \
		  check_stx/remove_extra_spaces.c \
		  check_stx/str_list.c

OBJS		= $(SRCS:.c=.o)

MAKELIB	= make -C ../lib/

CLEANLIB	= make clean -C ../lib/

FCLEANLIB	= make fclean -C ../lib/


all: $(NAME)

$(NAME): $(OBJS)
		$(MAKELIB)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(CLEANLIB)
		$(RM) $(OBJS)

fclean: clean
		$(FCLEANLIB)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
