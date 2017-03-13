/*
** asm.h for asm in /home/auzou_t/CPE_2014_corewar
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Dec  6 19:32:21 2014 Thibaud Auzou
** Last update Sun Dec 14 11:45:26 2014 Thibaud Auzou
*/

#ifndef ASM_H_
# define ASM_H_

# include "op.h"

typedef struct		s_param
{
  char			*param;
  int			val;
  int			param_size;
  struct s_param	*prev;
  struct s_param	*next;
}			t_param;

typedef struct		s_list
{
  char			*label;
  char			*ins;
  t_param		*params;
  int			tot_bytes;
  char			code_byte;
  struct s_list	*prev;
  struct s_list	*next;
}			t_list;

typedef struct		s_f_tab
{
  char			*name;
  void			(*f)();
}			t_f_tab;

typedef struct		s_str_list
{
  char			*str;
  struct s_str_list	*next;
}			t_str_list;

/*
** String List
*/
void			add_to_list(t_str_list **list, char *line);
void			free_list(t_str_list *l);
t_str_list		*file_to_list(int fd);

/*
** Check Syntaxe
*/
int			asm_syntax(char *file);
void			*check_malloc(int size);
int			check_labels(t_str_list *lines);
int			check_labels_def(t_str_list *lines, t_str_list *labels);
int			check_empty_label(t_str_list *list);
int			check_cmd(t_str_list *lines);
int			check_params(op_t *op, char *line, int nb_line);
int			check_ops(t_str_list *lines);
int			check_param_reg(char *param, int nb_line);
int			check_param_dir(char *param, int nb_line);
int			check_param_ind(char *param, int nb_line);
int			is_name(char *line);
int			is_comment(char *line);
int			is_extend(char *line);
int			is_cmd(char *line);
void			cmd_error(char *str);
void			remove_comment(t_str_list *l);
void			remove_extra_spaces(t_str_list *l);
char			*is_str_start(char *str, char *str2);
int			is_space(char c);
int			is_label_char(char c);
char			*is_label(char *line);

/*
** Building Binary File
*/
char			*get_champ_name(char *str);
int			build_binary_file(int fd, char *name);
int			build_content(int fd, char *name, header_t *h);

/*
** Get Header
*/
int			get_prog_name(char *name, int fd);
int			get_prog_size(t_list **list);
int			get_prog_comment(char *comment, int fd);
int			init_field_header(char*str, int nb);

/*
** Get Content
*/
int			get_content(t_list **list, int fd);
int			is_not_empty(char *str);
char			*get_label_name(char *str, int *i);
int			shift_str(char *str, int i);
char			**fetch_ins(int fd);

/*
** Fill List Elem
*/
int			fill_list_elem(t_list *elem, char *str, int fd);
int			fill_elem_params(t_list *elem, char **tab);
int			get_tot_bytes(t_list *elem);
char			get_code_byte(t_list *elem);
int			byte_code_not_needed(char *str);

/*
** Get Size
*/
int			get_params_size(t_list *elem);
int			init_f(t_f_tab *f);
int			init_f_function(t_f_tab *f);
void			live_size(t_param *p);
void			ld_size(t_param *p);
void			st_size(t_param *p);
void			add_size(t_param *p);
void			sub_size(t_param *p);
void			and_size(t_param *p);
void			zjmp_size(t_param *p);
void			ldi_size(t_param *p);
void			sti_size(t_param *p);
void			fork_size(t_param *p);
void			lld_size(t_param *p);
void			lldi_size(t_param *p);
void			lfork_size(t_param *p);
void			aff_size(t_param *p);

/*
** Write Content
*/
int			write_content(t_list **list, int fd);
int			write_ins(char *str, int fd);
int			write_byte_code(char nb, int fd);
int			write_params(t_list *tmp, t_param *p, int fd);
int			get_param_value(t_list *tmp, char *param);
int			get_value_label(char *label, t_list *tmp);

#endif /* !ASM_H_ */
