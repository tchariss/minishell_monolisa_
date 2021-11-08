#include "../minishell.h"

void	free_all_1(char *line, t_monna *lisa)
{
	int	i;

	i = 0;
	if (line)
		free (line);
	while (lisa->tokens[i])
	{
		free (lisa->tokens[i]);
		i++;
	}
	free (lisa->tokens);
}

void	free_all_2(char *line, t_monna *lisa)
{
	int	i;

	i = 0;
	if (line)
		free (line);
	if (lisa->tokens)
	{
		while (lisa->tokens[i])
			free (lisa->tokens[i++]);
		free (lisa->tokens);
	}
	i = 0;
	if (lisa->my_env)
	{
		while (lisa->my_env[i])
			free (lisa->my_env[i++]);
		free (lisa->my_env);
	}
	if (lisa->tmp_env)
		free (lisa->tmp_env);
}
