#include "../minishell.h"

int	ft_env(t_monna *lisa, int *count)
{
	int	i;

	i = 0;
	*count += 1;
	while (lisa->my_env[i])
	{
		if (ft_strchr(lisa->my_env[i], 61))
			ft_putendl_fd(lisa->my_env[i], 1);
		i++;
	}
	lisa->flag_command = 0;
	while (lisa->tokens[*count] && ft_operators_2(lisa->tokens[*count]))
		*count += 1;
	lisa->flag_error = 0;
	return (0);
}
