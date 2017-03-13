/*
** init.h for corewar in /home/auzou_t/CPE_2014_corewar/corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec 13 18:09:50 2014 Thibaud Auzou
** Last update Sun Dec 14 21:50:23 2014 Thibaud Auzou
*/

#ifndef INIT_H_
# define INIT_H_

# define MAX_CHAMP	4
# define DUMP_STX	"-dump"
# define NUM_STX	"-n"
# define MEM_STX	"-a"

typedef struct		s_options
{
  int			dump;
  int			num;
  int			mem;
  char			*name;
}			t_options;

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
  t_options		options;
  int			pc;
  char			carry;
  char			alive;
  int			cycle;
  int			reg[REG_NUMBER];
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct		s_ftab
{
  char			hex_val;
  void			(*f)();
}			t_ftab;

/*
** Load Options
*/
int			load_options(t_options options[], char **av);
int			init_options(t_options options[]);
int			print_too_much_champ(void);
int			load_dump(t_options options[], char *str);
int			load_num(t_options options[], char *str, int k);
int			load_mem(t_options options[], char *str, int k);
int			load_name(t_options options[], char *str, int k);
int			my_print_usage(void);
int			print_not_enough_champ(void);
int			print_wrong_option(char *str);
int		set_num(t_options options[]);
int		update_num(t_options options[]);

/*
** Champions List
*/
int		add_champ_to_list(char *name, int fd, t_champ **list);
t_champ	*add_elem_to_champ(t_champ *list,
				   char *comment,
				   int size,
				   t_options options);
t_champ	*set_list_to_first(t_champ *list);

/*
** Instructons List
*/
int		add_ins_to_list(t_inst **list, int *size, char *inst, int num);
char		*get_name_inst(char *inst, int ct);
char		*get_name_inst2(char *inst, int ct);
t_inst		*set_linst_to_first(t_inst *list);

/*
** Parameters List
*/
int		add_to_lparam(t_param **list, char *inst, int *size, int i);
int		get_value_lparam(char *tab_val, char *inst, int nb);
t_param	*set_lparam_to_first(t_param *list);
int		get_val(char *val, int size);

/*
** Set Size Functions
*/
void		print_tab(int *res);
int		init_ftab(t_ftab *f);
int		init_ftab_func(t_ftab *f);
void		size_live(char *inst, int ct, int *res);
void		size_ld(char *inst, int ct, int *res);
void		size_st(char *inst, int ct, int *res);
void		size_add(char *inst, int ct, int *res);
void		size_sub(char *inst, int ct, int *res);
void		size_and(char *inst, int ct, int *res);
void		size_zjmp(char *inst, int ct, int *res);
void		size_ldi(char *inst, int ct, int *res);
void		size_sti(char *inst, int ct, int *res);
void		size_fork(char *inst, int ct, int *res);
void		size_lldi(char *inst, int ct, int *res);
void		size_aff(char *inst, int ct, int *res);

/*
** Corewar
*/
t_champ	*init_game(t_options *options);
t_champ	*create_list(t_options *options, t_champ *my_champs);
int		get_fd(char *my_file);
char		*get_name(char *my_file, int fd);
char		*get_comment(char *my_file, int fd);
t_champ	*init_inst(t_champ *my_list);
t_inst		*get_inst(t_champ *my_list);
int		get_size_prog(char *my_file, int fd);
char		*get_all_inst(t_champ *my_file);
void		get_size_inst(char *inst,
			      int ct,
			      int *size_inst,
			      t_ftab *my_ftab);
void		init_tab_size(int *res);

#endif /* !INIT_H_ */
