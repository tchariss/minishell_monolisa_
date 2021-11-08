#include "../minishell.h"

int	search_n(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp("-n", str, 2) == 0)
	{
		while (str[++i])
		{
			if (str[i] != 'n')
				return (0);
		}
		return (1);
	}
	return (0);
}

void	ft_echo_2(int *new_i, int *count, t_monna *lisa)
{
	*count += 1;
	*new_i = 0;
	if (lisa->tokens[*count])
		*new_i = search_n(lisa->tokens[*count]);
}

int	ft_echo(t_monna *l, int *count)
{
	int	new_i;

	ft_echo_2(&new_i, count, l);
	while (l->tokens[*count] && ft_operators(l->tokens[*count]))
	{
		while (l->tokens[*count] && search_n(l->tokens[*count]) > 0)
			*count += 1;
		while (l->tokens[*count] && ft_operators(l->tokens[*count]))
		{
			ft_putstr_fd(l->tokens[*count], 1);
			if (l->tokens[*count + 1] && ft_operators(l->tokens[*count + 1]))
				write(1, " ", 1);
			*count += 1;
		}
	}
	if (new_i == 0)
		ft_putstr_fd("\n", 1);
	while (l->tokens[*count] && ft_operators_2(l->tokens[*count]))
		*count += 1;
	l->flag_command = 0;
	l->flag_error = 0;
	return (0);
}
