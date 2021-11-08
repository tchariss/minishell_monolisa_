#include "minishell.h"

void	check_ctrl_backslash(int sig)
{
	char	*s;

	s = "\b\b  \b\b";
	write(0, s, 6);
}

void	check_c(int sig)
{
	printf("\n");
	siglongjmp(g_buf_env, 1);
}

void	line_not_live(t_monna *lisa, char *line)
{
	write(0, "\b\b  \b\b", 6);
	write(1, "exit\n", 6);
	exit(1);
}

void	ft_while(t_monna *lisa, t_pars *pars)
{
	char	*line;

	while (lisa->status)
	{
		while (1)
			if (sigsetjmp(g_buf_env, 1) == 0)
				break ;
		write(1, "\033[33m", 5);
		line = readline("ʕ ᵔᴥᵔ ʔ : ");
		write(1, "\033[37m", 5);
		if (!line)
			line_not_live(lisa, line);
		add_history(ft_strjoin(line, "\n"));
		line = del_start_space(line);
		if (line == NULL)
			continue ;
		parser(line, lisa, pars);
		if (ft_search_syntax_error(lisa, line))
			continue ;
		ft_executor(lisa);
		free_all_1(line, lisa);
	}
	free_all_2(line, lisa);
}

int	main(int argc, char **argv, char **env)
{
	t_monna	lisa;
	t_pars	pars;

	if (!(ft_init_all(&lisa, env)))
		return (0);
	ft_shell_lvl(argv, &lisa);
	signal(SIGINT, check_c);
	signal(SIGQUIT, check_ctrl_backslash);
	ft_while(&lisa, &pars);
	return (0);
}
