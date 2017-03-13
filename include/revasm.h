/*
** revasm.h for  in /home/auzou_t/CPE_2014_corewar/include
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sun Dec 14 20:32:28 2014 Thibaud Auzou
** Last update Sun Dec 14 21:50:03 2014 Thibaud Auzou
*/

#ifndef REVASM_H_
# define REVASM_H_

# include "op.h"
# include "lib.h"

typedef struct		s_param
{
  char			*param;
  char			val[MAX_ARGS_NUMBER];
  int			param_size;
  struct s_param	*prev;
  struct s_param	*next;
}			t_param;

typedef struct		s_inst
{
  char			*label;
  char			*ins;
  char			val_ins;
  t_param		*params;
  int			tot_bytes;
  char			code_byte;
  struct s_inst	*prev;
  struct s_inst	*next;
}			t_inst;

typedef struct		s_champ
{
  char			*champ_name;
  int			champ_fd;
  int			size_prog;
  char			*comment;
  t_inst		*my_inst;
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct		s_ftab
{
  char			hex_val;
  void			(*f)();
}			t_ftab;

/*
** LIST CHAMP
*/
int			add_champ_to_list(char *name, int fd, t_champ **list);
t_champ		*add_elem_to_champ(t_champ *list,
					   char *comment,
					   int size);
t_champ		*set_list_to_first(t_champ *list);
void			print_champ_list(t_champ **list);
int			my_print_usage();

/*
** LIST INST
*/
int			add_ins_to_list(t_inst **list,
					int *size,
					char *inst,
					int ct);
char			*get_name_inst(char *inst, int ct);
char			*get_name_inst2(char *inst, int ct);
t_inst			*set_linst_to_first(t_inst *list);
void			print_list_inst(t_inst **list, int fd);

/*
** LIST PARAM
*/
int			add_to_lparam(t_param **list,
				      char *inst,
				      int *size,
				      int i);
int			get_value_lparam(char *tab_val, char *inst, int nb);
void			print_lparam_list(t_param **list, int fd, int st);
t_param		*set_lparam_to_first(t_param *list);
int			get_val(char *val, int size);

/*
** SET_SIZE
*/
void			print_tab(int *res);
int			init_ftab(t_ftab *f);
int			init_ftab_func(t_ftab *f);
void			size_live(char *inst, int ct, int *res);
void			size_ld(char *inst, int ct, int *res);
void			size_st(char *inst, int ct, int *res);
void			size_add(char *inst, int ct, int *res);
void			size_sub(char *inst, int ct, int *res);
void			size_and(char *inst, int ct, int *res);
void			size_zjmp(char *inst, int ct, int *res);
void			size_ldi(char *inst, int ct, int *res);
void			size_sti(char *inst, int ct, int *res);
void			size_fork(char *inst, int ct, int *res);
void			size_lldi(char *inst, int ct, int *res);
void			size_aff(char *inst, int ct, int *res);

/*
** REVASM
*/
t_champ		*init_game(int argc, char **argv);
t_champ		*create_list(int argc, char **argv, t_champ *my_champs);
int			get_fd(char *my_file);
char			*get_name(char *my_file, int fd);
char			*get_comment(char *my_file, int fd);
t_champ		*init_inst(t_champ *my_list);
t_inst			*get_inst(t_champ *my_list);
int			get_size_prog(char *my_file, int fd);
char			*get_all_inst(t_champ *my_file);
void			get_size_inst(char *inst,
				      int ct,
				      int *size_inst,
				      t_ftab *my_ftab);
void			init_tab_size(int *res);
int			init_new_fd(t_champ *my_champ, char *name);
char			*get_new_name(char *name);

#endif /* !REVASM_H_ */
