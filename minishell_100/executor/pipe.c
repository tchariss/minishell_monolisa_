#include "../minishell.h"

void	ft_pipe_stdin(t_monna *lisa)
{
	dup2(lisa->fd_output, 1);
	dup2(lisa->fildes[0], 0);
	close(lisa->fildes[0]);
}

void	ft_pipe_stdout(t_monna *lisa)
{
	dup2(lisa->fildes[1], 1);
	close(lisa->fildes[1]);
}

void	ft_pipe_end(t_monna *lisa)
{
	dup2(lisa->fd_input, 0);
	lisa->flag_pipe = 0;
}

void	ft_pipe2(t_monna *lisa, int *count)
{
	if (lisa->flag_pipe == 1)
		ft_pipe_stdin(lisa);
	if (lisa->flag_pipe == 2)
		ft_pipe_end(lisa);
	if (lisa->tokens[*count] && !ft_strcmp(lisa->tokens[*count], "|"))
		*count += 1;
}

void	ft_pipe(t_monna *l, int i)
{
	while (l->tokens[i] && ft_operators(l->tokens[i]))
		i++;
	if (l->tokens[i] && !ft_strcmp(l->tokens[i], "|") && l->tokens[i][2] == 0)
	{
		l->flag_pipe = 1;
		pipe(l->fildes);
		ft_pipe_stdout(l);
	}
	else
	{
		if (l->flag_pipe == 1)
			l->flag_pipe = 2;
		else
			l->flag_pipe = 0;
	}
}
