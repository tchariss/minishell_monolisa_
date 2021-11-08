#include "../minishell.h"

int	ft_len_space_tab(char *line, t_pars *len)
{
	while (line[len->i] == '\t' || line[len->i] == ' ')
		len->i++;
	if (line[len->i] == '\0')
		return (0);
	return (1);
}

void	ft_clean_tmp_env(t_monna *lisa)
{
	int	tmp;

	tmp = 0;
	while (tmp < 300)
	{
		lisa->tmp_env[tmp] = '\0';
		tmp++;
	}
}

int	proverka_isdigit(char *line, t_pars *len)
{
	if (ft_isdigit(line[len->i + 1]))
	{
		len->i += 2;
		return (1);
	}
	return (0);
}

void	ft_init_pars(t_monna *lisa, t_pars *pars)
{
	pars->j = 0;
	pars->flag = 1;
	lisa->flag_block_zvezda = 0;
	lisa->flag_block_operator = 0;
}
