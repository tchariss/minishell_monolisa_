#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

/* Standard file descriptors.  */
#define STDIN_FILENO    0       /* Standard input.  */
#define STDOUT_FILENO   1       /* Standard output.  */
#define STDERR_FILENO   2       /* Standard error output.  */

void	m(char *monna, int lisa);

typedef struct s_flag
{
    int f_echo;
    int f_cd;
    int f_pwd;
    int f_export;
    int f_unset;
    int f_env;
    int f_exit;
	int nothing;
    int ls;
    // int f8;
}				t_flag;      

typedef struct s_tok
{
	char **token;
	int flag;
}				t_tok;

typedef struct s_monna
{
	char	**commands;
	char	**my_env;
	char	**tokens;
	int		status;
}				t_monna;

void	m(char *monna, int lisa)
{
	write(lisa, monna, ft_strlen(monna));
}


void	ft_monnalisa(void)
{
	m("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!>''''''<!!!!!!!!!!!!!!!!!!!!!!!\n", 1);
	m("!!!!!!!!!!!!!!!!!!!!!!!!'''''`             ``'!!!!!!!!!!!!!!!!!!!\n", 1);
	m("!!!!!!!!!!!!!!!!!!!!''`          .....         `'!!!!!!!!!!!!!!!!\n", 1);
	m("!!!!!!!!!!!!!!!!!'`      .      :::::'            `'!!!!!!!!!!!!!\n", 1);
	m("!!!!!!!!!!!!!!!'     .   '     .::::'                `!!!!!!!!!!!\n", 1);
	m("!!!!!!!!!!!!!'      :          `````                   `!!!!!!!!!\n", 1);
	m("!!!!!!!!!!!!        .,cchcccccc,,.                       `!!!!!!!\n", 1);
	m("!!!!!!!!!!!     .-c?$$$$$$$$$$$$$$c,                      `!!!!!!\n", 1);
	m("!!!!!!!!!!    ,ccc$$$$$$$$$$$$$$$$$$$,                     `!!!!!\n", 1);
	m("!!!!!!!!!    z$$$$$$$$$$$$$$$$$$$$$$$$;.                    `!!!!\n", 1);
	m("!!!!!!!!    <$$$$$$$$$$$$$$$$$$$$$$$$$$:.                    `!!!\n", 1);
	m("!!!!!!!     $$$$$$$$$$$$$$$$$$$$$$$$$$$h;:.                   !!!\n", 1);
	m("!!!!!!'     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$h;.                   !!\n", 1);
	m("!!!!!'     <$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                   !!\n", 1);
	m("!!!!'      `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$F                   `!\n", 1);
	m("!!!!        c$$$$&&&$$$$$$$P##  ccc&&&&&&c                      !\n", 1);
	m("!!!         `cc .,.. c$$$$F    .,zcr                           !!\n", 1);
	m("!!!         .  dL    .?$$$   .,cc,      .,z$h.                 !!\n", 1);
	m("!!!!        <. $$c= <$d$$$   <$$$$=-=+c$$$$$$$                 !!\n", 1);
	m("!!!         d$$$hcccd$$$$$   d$$$hcccd$$$$$$$F                 !!\n", 1);
	m("!!         ,$$$$$$$$$$$$$$h d$$$$$$$$$$$$$$$$                 !!!\n", 1);
	m("!          `$$$$$$$$$$$$$$$<$$$$$$$$$$$$$$$$'                !!!!\n", 1);
	m("!          `$$$$$$$$$$$$$$$$c$$$$$$$$$$$$$P>                !!!!!\n", 1);
}

void	ft_monnalisa_2(void)
{
	m("!           ?$$$$$$$$$$$$??$c`$$$$$$$$$$$?>'                `!!!!\n", 1);
	m("!           `?$$$$$$I7?&&    ,$$$$$$$$$?>>'                  !!!!\n", 1);
	m("!.           <<?$$$$$$c.    ,d$$?$$$$$F>>''                  `!!!\n", 1);
	m("!!            <i?$Pc??$$r--c?cc  ,$$$$h;>''                  `!!!\n", 1);
	m("!!             $$$hccccccccc= cc$$$$$$$>>'                    !!!\n", 1);
	m("!              `?$$$$$$Fcccc  `c$$$$$>>>''                    `!!\n", 1);
	m("!                c?$$$$$cccccc$$$$cc>>>>'                      !!\n", 1);
	m("!                  c$$$$$$$$$$$$$F>>>>''                      `!!\n", 1);
	m("!                    c$$$$$$$$ccc>'''                           !\n", 1);
	m("!>                     `ccccccc                                 !\n", 1);
	m("!!;                       .                                     !\n", 1);
	m("!!!                       ?h.                                   !\n", 1);
	m("!!!!                       $$c,                                 !\n", 1);
	m("!!!!>                      ?$$$h.              .,c             !!\n", 1);
	m("!!!!!                       $$$$$$$$$hc,.,,cc$$$$$             !!\n", 1);
	m("!!!!!                  .,zcc$$$$$$$$$$$$$$$$$$$$$$             !!\n", 1);
	m("!!!!!               .z$$$$$$$$$$$$$$$$$$$$$$$$$$$$             !!\n", 1);
	m("!!!!!             ,d$$$$\033[35m|..@Tchariss..|\033[0m$$$$$$$$$    \n", 1);
	m("!!!!!           ,d$$$$$$\033[36m|..@Sabrenda..|\033[0m$$$$$$$$   \n", 1);
	m("!!!!!         ,d$$$$$$$$\033[31m|..MonnaLisa..|\033[0m$$$$$$$  \n", 1);
	m("!!!!>        c$$$$$$$$$$\033[32m|..MiniShell..|\033[0m$$$$$  \n", 1);
}

void	ft_davinci(void)
{
	ft_monnalisa();
	ft_monnalisa_2();
}

int	ft_lenmassive(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void search(t_flag *fl, char *str)
{
	if (strcmp(str,"echo") == 0)
		fl->f_echo = 1;
	else if (strcmp(str,"cd") == 0)
		fl->f_cd = 1;
	else if (strcmp(str,"pwd") == 0)
		fl->f_pwd = 1;
	else if (strcmp(str,"export") == 0)
		fl->f_export = 1;
	else if (strcmp(str,"unset") == 0)
		fl->f_unset = 1;
	else if (strcmp(str,"env") == 0)
		fl->f_env = 1;
    else if (strcmp(str,"ls") == 0)
		fl->f_exit = 1;
	else if (strcmp(str,"exit") == 0)
		fl->f_exit = 1;
	else
		fl->nothing = 1;
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	int		status;
	int		i;
	t_monna	lisa;
	pid_t id;

	t_flag fl;
	t_tok tok;

	if (argc != 1)
	{
		printf("Monoliza:");
		int i = 1;
		while(argv[i])
			printf(" %s: ", argv[i++]);
		printf("No such file or directory\n");
		return (0);
	}
	ft_bzero(&fl ,sizeof(t_flag));
	// printf("%d\n", fl.f1);
	ft_davinci();
	lisa.my_env = (char **)malloc(sizeof(char *) * ft_lenmassive(env) + 1);
	lisa.my_env[ft_lenmassive(env)] = NULL;
	i = -1;
	while (env[++i])
		lisa.my_env[i] = ft_strdup(env[i]);
	i = -1;
	lisa.status = 1;

	while (lisa.status)
	{
		ft_putstr_fd("\033[31m༼ つ ◕_◕ ༽つ\033[32m$ ", 1);
		// ft_putstr_fd(tok.token[0], 1);
		get_next_line(1, &line); //чтение ввода
		// int d = 0;
		// while(1)
		// {
			// ft_putstr_fd(line, 1);
			// printf("%d", fl.f_echo);
			// line = "echo";
			// ft_putstr_fd("sdfsdfsd \n", 1);
        ft_bzero(&fl ,sizeof(t_flag));
		search(&fl, line);
		if (fl.nothing == 1)
		{
			ft_putstr_fd("Monoliza:", 1);
			ft_putstr_fd(line , 1);
			ft_putstr_fd("command not found\n", 1);
			
		}
		else
			ft_putstr_fd("small step into the minishell!\n", 1);
       
		// 	int b;
		// 	if(strcmp(tok.token[0], str_t[b++] == 0)
		// 	{

		// }
		// // get_next_line(1, &line); 
		// if(strcmp("pwd", line) == 0)
		// {
		// 	printf("%s\n",getcwd(NULL, 0));
		// }
		// // if(strcmp("ls", line) == 0)
		// // {
		// // 	// id = fork();
		// // 	waitpid(id, 0, 0);
		// // 	if(id == 0)
		// // 	{
		// // 		execve("/bin/ls", argv, env);
		// // 	}
		// // }
		// if (strcmp("exit", line) == 0)
		// {
		// 	free(line);
		// 	break;
		// }
		free(line);
	}
	return (0);
}
