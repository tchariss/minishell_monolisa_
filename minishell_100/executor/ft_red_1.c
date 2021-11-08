#include "../minishell.h"

void	ft_red_ex_1(int *i, t_monna *l, int *fd, char *red)
{
	*i += 1;
	if (!ft_strcmp(red, ">"))
		*fd = open(l->tokens[*i], O_WRONLY | O_TRUNC | O_CREAT,
				S_IWRITE | S_IREAD);
	else
		*fd = open(l->tokens[*i], O_WRONLY | O_APPEND | O_CREAT,
				S_IWRITE | S_IREAD);
}

int	ft_red_ex_2(int *i, t_monna *lisa, int *count)
{
	ft_putstr_fd("minishell: ", 1);
	ft_putstr_fd(lisa->tokens[*i - 1], 1);
	ft_putendl_fd(" No such file or directory", 1);
	lisa->flag_red_files = 1;
	lisa->flag_command = 1;
	lisa->flag_error = 1;
	while (lisa->tokens[*count] && search_arg_2(lisa, count))
		*count += 1;
	return (-1);
}

int	ft_red_ex_3(t_monna *lisa, int *fd)
{
	lisa->flag_red_files = 1;
	if (*fd > 0)
		close(*fd);
	if (*fd == -1)
		return (1);
	return (0);
}

void	ft_redirect_executor(t_monna *l, int i, int *count)
{
	int	fd;

	while (l->tokens[i] && ft_operators_red(l->tokens[i]))
	{
		if ((!(ft_strcmp(l->tokens[i], "|")) && l->tokens[2] == 0))
			break ;
		if (ft_red_serch(l->tokens[i]))
		{
			if (!(ft_strcmp(l->tokens[i], ">")) && l->tokens[i][2] == 0)
				ft_red_ex_1(&i, l, &fd, ">");
			else if (!(ft_strcmp(l->tokens[i], "<")) && l->tokens[i][2] == 0)
			{
				i++;
				fd = open(l->tokens[i], O_RDONLY);
				if (fd == -1)
					if (ft_red_ex_2(&i, l, count) == -1)
						return ;
			}
			else if (!(ft_strcmp(l->tokens[i], ">>")) && l->tokens[i][3] == 0)
				ft_red_ex_1(&i, l, &fd, ">");
			if (ft_red_ex_3(l, &fd))
				return ;
		}
		i++;
	}
}
