##
## Makefile for corewar in /home/auzou_t/CPE_2014_corewar
## 
## Made by Thibaud Auzou
## Login   <auzou_t@epitech.net>
## 
## Started on  Sat Dec  6 19:10:52 2014 Thibaud Auzou
## Last update Sun Dec 14 21:11:39 2014 Thibaud Auzou
##

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wextra -Wall -Werror -Wno-unused-parameter
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -I./include/ -I../include/

LDFLAGS	= -lmy -L./lib/

ASMNAME	= asm/asm

VMNAME		= corewar/corewar

REVASMNAME	= revasm/revasm

ASMSRCS	= asm/main.c \
		  asm/misc/op.c \
		  asm/get_header/get_header.c \
		  asm/get_content/get_content.c \
		  asm/get_content/fill_list_elem.c \
		  asm/get_size/get_size.c \
		  asm/get_size/live_size.c \
		  asm/get_size/ld_size.c \
		  asm/get_size/st_size.c \
		  asm/get_size/add_size.c \
		  asm/get_size/sub_size.c \
		  asm/get_size/and_size.c \
		  asm/get_size/zjmp_size.c \
		  asm/get_size/ldi_size.c \
		  asm/get_size/sti_size.c \
		  asm/get_size/fork_size.c \
		  asm/get_size/lld_size.c \
		  asm/get_size/lldi_size.c \
		  asm/get_size/lfork_size.c \
		  asm/get_size/aff_size.c \
		  asm/write_content/write_content.c \
		  asm/write_content/get_param_value.c\
		  asm/check_stx/asm_syntax.c \
		  asm/check_stx/asm_tests.c \
		  asm/check_stx/check_malloc.c \
		  asm/check_stx/cmd_syntax2.c \
		  asm/check_stx/cmd_syntax.c \
		  asm/check_stx/label_syntax2.c \
		  asm/check_stx/label_syntax.c \
		  asm/check_stx/op_syntax.c \
		  asm/check_stx/param_syntax2.c \
		  asm/check_stx/param_syntax.c \
		  asm/check_stx/remove_comment.c \
		  asm/check_stx/remove_extra_spaces.c \
		  asm/check_stx/str_list.c

VMSRCS		= corewar/main.c \
		  corewar/misc/op.c \
		  corewar/list/list_champ.c \
		  corewar/list/list_inst.c \
		  corewar/init/init_game.c \
		  corewar/init/init_inst.c \
		  corewar/set_size/get_size_inst.c \
		  corewar/msg_options/msg_options.c \
		  corewar/load_options/load_options.c \
		  corewar/load_options/load_functions.c \
		  corewar/set_size/size_live.c \
		  corewar/set_size/size_ld.c \
		  corewar/set_size/size_st.c \
		  corewar/set_size/size_add.c \
		  corewar/set_size/size_sub.c \
		  corewar/set_size/size_and.c \
		  corewar/set_size/size_zjmp.c \
		  corewar/set_size/size_ldi.c \
		  corewar/set_size/size_fork.c \
		  corewar/set_size/size_lldi.c \
		  corewar/set_size/size_aff.c \
		  corewar/set_size/size_sti.c \
		  corewar/list/list_param.c \
		  corewar/place_champions/fill_board.c \
		  corewar/place_champions/set_champs_on_board.c \
		  corewar/print/print_board.c \
		  corewar/delete/delete.c \
		  corewar/delete/free.c \
		  corewar/do_action/play_corewar.c \
		  corewar/do_action/do_action.c \
		  corewar/do_action/do_live.c \
		  corewar/do_action/do_ld.c \
		  corewar/do_action/do_st.c \
		  corewar/do_action/do_add.c \
		  corewar/do_action/do_sub.c \
		  corewar/do_action/do_and.c \
		  corewar/do_action/do_or.c \
		  corewar/do_action/do_xor.c \
		  corewar/do_action/do_zjmp.c \
		  corewar/do_action/do_ldi.c \
		  corewar/do_action/do_sti.c \
		  corewar/do_action/do_fork.c \
		  corewar/do_action/do_lld.c \
		  corewar/do_action/do_lldi.c \
		  corewar/do_action/do_lfork.c \
		  corewar/do_action/do_aff.c

REVASMSRCS	= revasm/src/main.c \
		  revasm/op.c \
		  revasm/src/list/list_champ.c \
		  revasm/src/list/list_inst.c \
		  revasm/src/init_game.c \
		  revasm/src/init_inst.c \
		  revasm/src/get_size_inst.c \
		  revasm/src/my_messages.c \
		  revasm/src/set_size/size_live.c \
		  revasm/src/set_size/size_ld.c \
		  revasm/src/set_size/size_st.c \
		  revasm/src/set_size/size_add.c \
		  revasm/src/set_size/size_sub.c \
		  revasm/src/set_size/size_and.c \
		  revasm/src/set_size/size_zjmp.c \
		  revasm/src/set_size/size_ldi.c \
		  revasm/src/set_size/size_fork.c \
		  revasm/src/set_size/size_lldi.c \
		  revasm/src/set_size/size_aff.c \
		  revasm/src/set_size/size_sti.c \
		  revasm/src/list/list_param.c

ASMOBJS	= $(ASMSRCS:.c=.o)

VMOBJS		= $(VMSRCS:.c=.o)

REVASMOBJS	= $(REVASMSRCS:.c=.o)

MAKELIB	= make -C lib/

CLEANLIB	= make clean -C lib/

FCLEANLIB	= make fclean -C lib/


all: $(ASMNAME) $(VMNAME) $(REVASMNAME)

$(ASMNAME): $(ASMOBJS)
		$(MAKELIB)
		$(CC) $(ASMOBJS) -o $(ASMNAME) $(LDFLAGS)

$(VMNAME): $(VMOBJS)
		$(MAKELIB)
		$(CC) $(VMOBJS) -o $(VMNAME) $(LDFLAGS)

$(REVASMNAME): $(REVASMOBJS)
		$(MAKELIB)
		$(CC) $(REVASMOBJS) -o $(REVASMNAME) $(LDFLAGS)

clean:
		$(RM) $(ASMOBJS) $(VMOBJS) $(REVASMOBJS)
		$(CLEANLIB)

fclean: clean
		$(RM) $(ASMNAME) $(VMNAME) $(REVASMNAME)
		$(FCLEANLIB)

re: fclean all

.PHONY: all clean fclean re
