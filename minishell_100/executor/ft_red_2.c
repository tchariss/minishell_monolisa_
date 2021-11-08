#include "../minishell.h"

int	ft_operators_red(char *str)
{
	if ((!(ft_strcmp(str, "&&")) && str[3] == 0)
		|| (!(ft_strcmp(str, "||")) && str[3] == 0)
		|| (!(ft_strcmp(str, "|")) && str[2] == 0)
		|| (!(ft_strcmp(str, ";")) && str[2] == 0))
		return (0);
	return (1);
}

void	ft_redirect_end(t_monna *lisa)
{
	if (lisa->flag_red_input)
	{
		dup2(lisa->fd_input, 0);
	}
	if (lisa->flag_red_output)
	{
		dup2(lisa->fd_output, 1);
	}
}

void	ft_red_1(t_monna *lisa, int *count)
{
	int	fd;

	lisa->flag_red_output = 1;
	*count += 1;
	fd = open(lisa->tokens[*count],
			O_WRONLY | O_TRUNC | O_CREAT, S_IWRITE | S_IREAD);
	dup2(fd, 1);
	close(fd);
}

void	ft_red_2(t_monna *lisa, int *count)
{
	int	fd;

	lisa->flag_red_input = 1;
	*count += 1;
	fd = open(lisa->tokens[*count], O_RDONLY);
	dup2(fd, 0);
	close(fd);
}

void	ft_red_3(t_monna *lisa, int *count)
{
	int	fd;

	lisa->flag_red_output = 1;
	*count += 1;
	fd = open(lisa->tokens[*count],
			O_WRONLY | O_APPEND | O_CREAT, S_IWRITE | S_IREAD);
	dup2(fd, 1);
	close(fd);
}
