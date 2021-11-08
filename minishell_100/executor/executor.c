#include "../minishell.h"

void	ft_ampersant(t_monna *lisa, int *count)
{
	lisa->flag_red_files = 0;
	if (lisa->flag_command)
	{
		while (lisa->tokens[*count] && ft_strcmp(lisa->tokens[*count], "||")
			&& ft_strcmp(lisa->tokens[*count], ";"))
			*count += 1;
	}
	else
		*count += 1;
}

void	ft_ili(t_monna *lisa, int *count)
{
	lisa->flag_red_files = 0;
	if (!lisa->flag_command)
	{
		while (lisa->tokens[*count] && ft_strcmp(lisa->tokens[*count], "|")
			&& ft_strcmp(lisa->tokens[*count], "&&")
			&& ft_strcmp(lisa->tokens[*count], ";"))
			*count += 1;
	}
	else
	{
		*count += 1;
	}
}

void	ft_command_start(t_monna *lisa, int *count)
{
	if (!(ft_boss_reg(lisa->tokens[*count], "env")))
		lisa->flag_command = ft_env(lisa, count);
	else if (!(ft_boss_reg(lisa->tokens[*count], "cd")))
		lisa->flag_command = ft_cd(lisa, count);
	else if (!(ft_boss_reg(lisa->tokens[*count], "pwd")))
		lisa->flag_command = ft_pwd(lisa, count);
	else if (!(ft_strcmp(lisa->tokens[*count], "export")))
		lisa->flag_command = ft_export(lisa, count);
	else if (!(ft_strcmp(lisa->tokens[*count], "unset")))
		lisa->flag_command = ft_unset(lisa, count);
	else if (!(ft_boss_reg(lisa->tokens[*count], "echo")))
		lisa->flag_command = ft_echo(lisa, count);
	else if (!(ft_strcmp(lisa->tokens[*count], "exit")))
		ft_exit(lisa, count);
}

void	ft_executor(t_monna *lisa)
{
	int	count;

	lisa->flag_command = 0;
	count = 0;
	while (lisa->tokens[count])
	{
		ft_pipe(lisa, count);
		if (!lisa->flag_red_files)
			ft_redirect_executor(lisa, count, &count);
		ft_redirect_executor_2(lisa, count, &count);
		if (ft_search_com(lisa->tokens[count]))
			ft_command_start(lisa, &count);
		else if (!ft_strcmp(lisa->tokens[count], "&&"))
			ft_ampersant(lisa, &count);
		else if (!ft_strcmp(lisa->tokens[count], "||"))
			ft_ili(lisa, &count);
		else if (ft_red_serch(lisa->tokens[count]))
			ft_redred(lisa, &count);
		else if (!ft_strcmp(lisa->tokens[count], ";"))
			ft_tochka(lisa, &count);
		else
			ft_else(lisa, &count);
		ft_pipe2(lisa, &count);
		ft_redirect_end(lisa);
	}
}
