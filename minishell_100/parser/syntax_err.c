#include "../minishell.h"

int	ft_err_1(t_monna *l)
{
	int	flag_1;
	int	i;

	flag_1 = 0;
	i = -1;
	while (l->tokens[++i] && flag_1 != 2)
	{
		if (flag_1 == 0
			&& ((!ft_strcmp(l->tokens[i], "&&") && l->tokens[i][3] == 0)
			|| (!ft_strcmp(l->tokens[i], "||") && l->tokens[i][3] == 0)
			|| (!ft_strcmp(l->tokens[i], "|") && l->tokens[i][2] == 0)
			|| (!ft_strcmp(l->tokens[i], ";") && l->tokens[i][2] == 0)))
			flag_1 = 2;
		else if (flag_1 == 1
			&& ((!ft_strcmp(l->tokens[i], "&&") && l->tokens[i][3] == 0)
			|| (!ft_strcmp(l->tokens[i], "||") && l->tokens[i][3] == 0)
			|| (!ft_strcmp(l->tokens[i], "|") && l->tokens[i][2] == 0)
			|| (!ft_strcmp(l->tokens[i], ";") && l->tokens[i][2] == 0)))
			flag_1 = 0;
		else
			flag_1 = 1;
	}
	return (flag_1);
}

int	ft_err_2(t_monna *l)
{
	int	flag_1;
	int	i;

	flag_1 = 0;
	i = 0;
	while (l->tokens[i])
		i++;
	if (i == 0)
		return (flag_1);
	if ((!ft_strcmp(l->tokens[i - 1], "&&") && l->tokens[i - 1][3] == 0)
		|| (!ft_strcmp(l->tokens[i - 1], "||") && l->tokens[i - 1][3] == 0)
		|| (!ft_strcmp(l->tokens[i - 1], "|") && l->tokens[i - 1][2] == 0)
		|| (!ft_strcmp(l->tokens[i - 1], "<") && l->tokens[i - 1][2] == 0)
		|| (!ft_strcmp(l->tokens[i - 1], "<<") && l->tokens[i - 1][3] == 0)
		|| (!ft_strcmp(l->tokens[i - 1], ">") && l->tokens[i - 1][2] == 0)
		|| (!ft_strcmp(l->tokens[i - 1], ">>") && l->tokens[i - 1][3] == 0))
	{
		flag_1 = 2;
		return (flag_1);
	}
	return (flag_1);
}

void	er3_init(t_er3 *er)
{
	er->flag = 0;
	er->i = -1;
}

int	ft_err_3(t_monna *l)
{
	t_er3	er;

	er3_init(&er);
	while (l->tokens[++er.i] && er.flag != 2)
	{
		if (er.flag == 0
			&& ((!ft_strcmp(l->tokens[er.i], ">") && l->tokens[er.i][2] == 0)
			|| (!ft_strcmp(l->tokens[er.i], "<") && l->tokens[er.i][2] == 0)
			|| (!ft_strcmp(l->tokens[er.i], ">>") && l->tokens[er.i][3] == 0)
			|| (!ft_strcmp(l->tokens[er.i], "<<") && l->tokens[er.i][3] == 0)))
			er.flag = 1;
		else if (er.flag == 1
			&& ((!ft_strcmp(l->tokens[er.i], "&&") && l->tokens[er.i][3] == 0)
			|| (!ft_strcmp(l->tokens[er.i], "||") && l->tokens[er.i][3] == 0)
			|| (!ft_strcmp(l->tokens[er.i], "|") && l->tokens[er.i][2] == 0)
			|| (!ft_strcmp(l->tokens[er.i], ";") && l->tokens[er.i][2] == 0)
			|| (!ft_strcmp(l->tokens[er.i], ">") && l->tokens[er.i][2] == 0)
			|| (!ft_strcmp(l->tokens[er.i], ">>") && l->tokens[er.i][3] == 0)
			|| (!ft_strcmp(l->tokens[er.i], "<") && l->tokens[er.i][2] == 0)
			|| (!ft_strcmp(l->tokens[er.i], "<<") && l->tokens[er.i][3] == 0)))
			er.flag = 2;
		else
			er.flag = 0;
	}
	return (er.flag);
}

int	ft_search_syntax_error(t_monna *l, char *line)
{
	int	flag_1;
	int	q;
	int	w;
	int	e;

	l->fd_input = dup(0);
	l->fd_output = dup(1);
	q = ft_err_1(l);
	w = ft_err_2(l);
	e = ft_err_3(l);
	if (q == 2 || w == 2 || e == 2)
	{
		write(1, "minishell: syntax error near unexpected token\n", 46);
		l->flag_error = 258;
		free_all_1(line, l);
		return (1);
	}
	return (0);
}
