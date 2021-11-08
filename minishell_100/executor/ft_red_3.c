#include "../minishell.h"

void	ft_red_4_sup(t_red_4 *aa, t_monna *lisa, int *count)
{
	while (1)
	{
		ft_putstr_fd("> ", 1);
		get_next_line(1, &aa->str);
		if (!ft_strcmp(aa->str, lisa->tokens[*count]))
		{
			if (aa->str)
				free (aa->str);
			break ;
		}
		if (!lisa->list)
		{
			lisa->list = ft_lstnew((char *)aa->str);
			aa->tmp = lisa->list;
		}
		else
		{
			aa->tmp->next = ft_lstnew((char *)aa->str);
			aa->tmp = aa->tmp->next;
		}
	}
}

void	ft_red_4(t_monna *lisa, int *count)
{
	t_red_4	aa;

	lisa->flag_red_output = 1;
	lisa->flag_red_4 = 1;
	dup2(1, aa.temp_fd_out);
	dup2(lisa->fd_output, 1);
	*count += 1;
	ft_red_4_sup(&aa, lisa, count);
	aa.tmp = lisa->list;
	aa.fd = open("1", O_WRONLY | O_TRUNC | O_CREAT, S_IWRITE | S_IREAD);
	while (aa.tmp)
	{
		if (aa.tmp->content)
			ft_putendl_fd(aa.tmp->content, aa.fd);
		aa.tmp = aa.tmp->next;
	}
	ft_list_clear(&lisa->list);
	lisa->list = NULL;
	dup2(aa.temp_fd_out, 1);
	close(aa.temp_fd_out);
	close(aa.fd);
}

void	ft_redirect_executor_2(t_monna *l, int i, int *count)
{
	while (l->tokens[i] && ft_operators(l->tokens[i]))
		i++;
	if (l->tokens[i] && ft_red_serch(l->tokens[i]))
	{
		while (l->tokens[i] && !ft_red_serch_2(l->tokens[i]))
		{
			if (!(ft_strcmp(l->tokens[i], ">")) && l->tokens[i][2] == 0)
				ft_red_1(l, &i);
			else if (!(ft_strcmp(l->tokens[i], "<")) && l->tokens[i][2] == 0)
				ft_red_2(l, &i);
			else if (!(ft_strcmp(l->tokens[i], ">>")) && l->tokens[i][3] == 0)
				ft_red_3(l, &i);
			else if (!(ft_strcmp(l->tokens[i], "<<")) && l->tokens[i][3] == 0)
				ft_red_4(l, &i);
			else
				i++;
		}
	}
}
