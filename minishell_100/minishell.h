#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <string.h>
# include <getopt.h>
# include <errno.h>
# include <setjmp.h>
# include <signal.h>
# include <termios.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_monna
{
	t_list	*list;
	char	**my_env;
	char	**tokens;
	char	**pars_tokk;
	char	*tmp_env;
	int		status;
	int		fildes[2];
	int		shell_lvl;
	int		flag_pipe;
	int		fd_input;
	int		fd_output;
	int		flag_error;
	int		flag_block_zvezda;
	int		flag_block_operator;
	int		flag_command;
	int		flag_red_files;
	int		flag_red_ex;
	int		flag_red_input;
	int		flag_red_output;
	int		flag_bonus_red;
	int		flag_red_4;
}				t_monna;

typedef struct s_pars
{
	int		i;
	int		j;
	int		word;
	int		flag;
	int		ecran;
	int		count;
	char	c;
}				t_pars;

typedef struct s_red_4
{
	int		temp_fd_out;
	char	*str;
	t_list	*tmp;
	int		fd;
}				t_red_4;

typedef struct s_unset
{
	int		i;
	int		b;
	char	**new_mas;
	int		k;
}				t_unset;

typedef struct s_exp
{
	int		i;
	int		s_i;
	int		len;
	char	*temp;
}				t_exp;

sigjmp_buf	g_buf_env;

typedef struct s_er3
{
	int		i;
	int		flag;
}				t_er3;

typedef struct s_copy_mass
{
	char	**str;
	int		j;
	int		tmp;
}				t_copy_mass;

typedef struct s_ept
{
	DIR				*mydir;
	struct dirent	*myfile;
	struct stat		mystat;
}				t_ept;

typedef struct s_vshoke
{
	int		flag;
	int		a;
	int		i;
	int		count;
	int		x;
	int		j;
}				t_vshoke;

typedef struct s_any
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	char	*str;
	char	*tmp;
	char	**mas;
}				t_any;

void	ft_shell_lvl(char **argv, t_monna *lisa);
void	ft_shell_else(t_monna *lisa, int u, char **argv);
void	ft_shell_if(t_monna *lisa, int u);
int		ft_init_all(t_monna	*lisa, char **env);
int		parser(char *line, t_monna *lisa, t_pars *pars);
int		ft_operator(t_pars *len, char *line);
int		ft_len_words(char *line, t_monna *lisa);
int		ft_len_space_tab(char *line, t_pars *len);
int		proverka_isdigit(char *line, t_pars *len);
int		ft_zvezda_v_shoke(char *str, char *dir_name);
int		ft_memory_pars(t_monna *lisa, char *line, t_pars *pars);
int		ft_zvezda_nachalo(char *str, char *dir_name, int *flag);
int		ft_zvezda_seredina(char *str, char *dir_name, int *flag);
int		ft_zvezda_konec(char *str, char *dir_name, int *flag);
int		ft_zvezda_nachalo_2(int i, char *str, char *dir_name);
int		ft_zvezda_seredina_2(char *str, char *dir_name, int *flag);
int		ft_zvezda_konec_2(int i, char *str, char *dir_name);
char	*del_start_space(char *line);
void	ft_len_kov_1(t_pars *n, char *l, t_monna *lisa);
void	ft_len_kov_2(t_pars *len, char *line);
void	ft_len_kov_pars_1(t_pars *pars, char *line, t_monna *lisa);
void	ft_len_kov_pars_2(t_pars *pars, char *line, t_monna *lisa);
void	ft_len_alpha(char *line, t_pars *len, t_monna *lisa);
void	ft_len_alpha_pars(char *line, t_pars *pars, t_monna *lisa);
void	ft_tochka_zapitaya(t_pars *len, char *line);
void	ft_tochka_zapitaya_pars(t_pars *pars, char *line, t_monna *lisa);
void	ft_operator_pars(t_pars *pars, char *line, t_monna *lisa);
void	ft_ecran(char *line, t_pars *len);
void	ft_ecran_pars(t_pars *pars, char *line, t_monna *lisa);
void	ft_redirect_pars(t_pars *len, t_monna *lisa, char *line);
void	ft_redirect(t_pars *len, char *line);
void	ft_dollar_ili_net(t_monna *lisa, t_pars *len);
void	ft_dollar_ili_net_pars(t_monna *lisa, t_pars *pars);
void	ft_kov_dollar(t_monna *lisa, char *line, t_pars *len);
void	ft_kov_dollar_pars(t_monna *lisa, char *line, t_pars *pars);
void	ft_clean_tmp_env(t_monna *lisa);
void	ft_zvezda_epta(t_monna *lisa, int nomer_ukaza);
void	ft_init_pars(t_monna *lisa, t_pars *pars);
void	ft_block_operator(t_monna *lisa, int nomer_ukaza);
void	er3_init(t_er3 *er);
int		ft_err_1(t_monna *lisa);
int		ft_err_2(t_monna *lisa);
int		ft_err_3(t_monna *lisa);
int		ft_search_syntax_error(t_monna *lisa, char *line);
int		ft_search_com(char *str);
int		ft_red_serch(char *str);
void	ft_executor(t_monna *lisa);
int		ft_env(t_monna *lisa, int *count);
int		ft_operators(char *str);
void	ft_command_start(t_monna *lisa, int *count);
void	ft_ili(t_monna *lisa, int *count);
void	ft_ampersant(t_monna *lisa, int *count);
int		ft_any_argument(t_monna *lisa, int *count);
void	ft_free_mass(char	**mas);
char	**ft_copy_massive(t_monna *lisa, int i);
int		ft_search_com(char *str);
int		ft_operators(char *str);
int		ft_operators_2(char *str);
void	ft_proverka_absol_relat(t_any *any);
void	ft_tochka(t_monna *lisa, int *count);
void	ft_else(t_monna *lisa, int *count);
int		ft_lenmassive(char **str);
int		ft_init_all(t_monna	*lisa, char **env);
void	ft_list_clear(t_list **head);
int		ft_pwd(t_monna *lisa, int *count);
void	ft_monnalisa(void);
void	ft_monnalisa_2(void);
void	m(char *monna, int lisa);
void	ft_davinci(void);
void	free_all_1(char *line, t_monna *lisa);
void	free_all_2(char *line, t_monna *lisa);
void	ft_pipe(t_monna *lisa, int i);
void	ft_pipe_stdin(t_monna *lisa);
void	ft_pipe_end(t_monna *lisa);
void	ft_pipe2(t_monna *lisa, int *count);
void	ft_redirect_executor(t_monna *l, int i, int *count);
void	ft_redirect_executor_2(t_monna *lisa, int i, int *count);
int		ft_red_serch_2(char *str);
int		search_arg_2(t_monna *lisa, int *count);
void	ft_red_4(t_monna *lisa, int *count) ;
void	ft_red_3(t_monna *lisa, int *count);
void	ft_red_2(t_monna *lisa, int *count);
void	ft_red_1(t_monna *lisa, int *count);
void	ft_redirect_end(t_monna *lisa);
int		ft_operators_red(char *str);
void	ft_redred(t_monna *l, int *count);
void	ft_red_ex_1(int *i, t_monna *l, int *fd, char *red);
int		ft_red_ex_2(int *i, t_monna *lisa, int *count);
int		t_red_ex_3(t_monna *lisa, int *fd);
int		ft_echo(t_monna *lisa, int *count);
int		search_n(char *str);
int		ft_cd(t_monna *lisa, int *count);
void	change_oldpwd(t_monna *lisa, char *cur_k);
void	go_change_pat_pwd(t_monna *lisa, char *s);
int		search_home(t_monna *lisa);
int		search_arg(t_monna *lisa, int *count);
int		ft_copy_massive_env(t_monna *lisa, char *tmp);
char	*strchr_boss(const char *s, int c);
void	err_cd(t_monna *lisa, int *count);
int		ft_export(t_monna *lisa, int *count);
void	sort_env(t_monna *lisa);
void	print_sort_env(t_monna *lisa);
void	err_exp(t_monna *lisa, char *s);
int		search_per_env(t_monna *lisa, char *str, int len);
int		len_arg(char *str);
void	add_per_env(t_monna *lisa, char *str);
void	keep_exp(t_monna *lisa, char *str);
int		ft_unset(t_monna *lisa, int *count);
int		delete_per(t_monna *lisa, char *str);
void	err_uns(t_monna *lisa, char *s);
int		ft_exit(t_monna *lisa, int *count);
int		boss_isdigit(char *c);
int		err_many_arg(t_monna *lisa);
int		ft_lenstr(char **mas);
int		boss_atoi(t_monna *lisa, int *count, char *str);
int		ft_boss_reg(char *s1, char *s2);
void	err_num_arg(t_monna *lisa, char *str);
int		srch_null_arg(int c);
int		srch_next_arg(int c);
int		tfy_ti_arg(t_monna *l, char *s);
void	ft_konec(t_monna *lisa, char *str, t_unset *set);

#endif
