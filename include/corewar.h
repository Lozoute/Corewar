/*
** corewar.h for corewar in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 07:19:14 2014 Thibaud Auzou
** Last update Sun Dec 14 19:32:30 2014 Thibaud Auzou
*/

#ifndef COREWAR_H_
# define COREWAR_H_

typedef struct		s_board
{
  t_champ		*champ;
  t_inst		*ins;
  char			code;
  t_param		*param;
  int			param_byte;
}			t_board;

/*
** Place Champions On Board
*/
int			init_board(t_board *board);
int			set_champs_on_board(t_board *board,
					    t_champ **champs);
void			check_tab_pos(int tab[][5], t_champ *champs);
void			fill_tab(int tab[][5], t_champ *champ);
void			init_tab_pos(int tab[][5]);
void			init_priority(t_champ *champ, int tab[][5]);
void			print_tab_pos(int tab[][5]);

/*
** Fill Board
*/
void			fill_board(t_board *board,
				   t_champ **champs,
				   int tab[2][5]);
void			fill_board_with_champ(t_board *board,
					      t_champ *champ,
					      int i);
void			fill_board_with_code(t_board *board,
					     char code,
					     int i,
					     t_champ *champ);
void			fill_board_with_param(t_board *board,
					      t_param *p,
					      t_champ *champ,
					      int size);

/*
** Play Corewar
*/
int			init_dof(int (**dof)());
int			play_corewar(t_board *board,
				     t_champ **champs,
				     int (**dof)());
int			print_state_of_game(t_board *board);
int			do_cycle(t_board *board,
				 t_champ **champs,
				 int (**dof)());
int			get_cycle(t_inst *ins);
int			do_action(t_board *board,
			  t_champ **champs,
			  t_champ *champ,
			  int (**dof)());
int			get_real_value_param(char *tab, int size);

/*
** Delete
*/
int			kill_the_dead(t_champ **champs);
int			init_new_cycle(t_champ **champs);
int			there_is_a_winner(t_champ **champs);
int			delete_champ(t_champ **champs, t_champ *tmp);
int			free_champ(t_champ *champ);
int			free_ins(t_inst *ins);
int			free_param(t_param *p);

/*
** Do Action
*/
int			do_live(t_board *board,
				t_champ **champs,
				t_champ *champ);
int			get_value_on_board(t_board *board,
					   int ind,
					   int nb);
int			set_value_on_board(t_board *board,
					   int ind,
					   char *buff,
					   int nb);
int			do_ld(t_board *board,
			      t_champ **champs,
			      t_champ *champ);
int			get_value_ld(t_board *board,
				     t_param *p,
				     int nb,
				     t_champ *champ);
int			do_st(t_board *board,
			      t_champ **champs,
			      t_champ *champ);
int			do_add(t_board *board,
			       t_champ **champs,
			       t_champ *champ);
int			do_sub(t_board *board,
			       t_champ **champs,
			       t_champ *champ);
int			do_and(t_board *board,
			       t_champ **champs,
			       t_champ *champ);
int			get_value_p(t_board *board,
				    t_param *p,
				    t_champ *champ);
int			do_or(t_board *board,
			      t_champ **champs,
			      t_champ *champ);
int			do_xor(t_board *board,
			       t_champ **champs,
			       t_champ *champ);
int			do_zjmp(t_board *board,
				t_champ **champs,
				t_champ *champ);
int			do_ldi(t_board *board,
			       t_champ **champs,
			       t_champ *champ);
int			get_value_ldi(t_param *p,
				      t_champ *champ);
int			do_sti(t_board *board,
			       t_champ **champs,
			       t_champ *champ);
int			do_fork(t_board *board,
				t_champ **champs,
				t_champ *champ);
int			copy_champ(t_champ *dest,
				   t_champ *src);
t_inst			*copy_ins(t_inst *src);
t_param		*copy_params(t_param *src);
int			add_fork_to_list(t_champ **champs,
					 t_champ *elem);
int			do_lld(t_board *board,
			       t_champ **champs,
			       t_champ *champ);
int			get_value_lld(t_board *board,
				      t_param *p,
				      int nb,
				      t_champ *champ);
int			do_lldi(t_board *board,
				t_champ **champs,
				t_champ *champ);
int			do_lfork(t_board *board,
				 t_champ **champs,
				 t_champ *champ);
int			do_aff(t_board *board,
			       t_champ **champs,
			       t_champ *champ);

/*
** Print Board
*/
int			print_board(t_board *board);
char			*fetch_color(t_champ *champ);
int			fetch_val(t_board *elem);
int			convert_hex(char c);
int			print_alive(t_champ *champ);

#endif /* !COREWAR_H_ */
