#include "../minishell.h"

void	ft_len_kov_1(t_pars *len, char *line, t_monna *lisa)
{
	len->c = line[len->i++];
	while (1)
	{
		len->count++;
		if (line[len->i] == '\\')
			if ((line[++len->i] != '\0') && len->count++)
				len->i++;
		if (line[len->i] == '\0')
		{
			line[len->i++] = len->c;
			line[len->i] = '\0';
			len->flag = 0;
			break ;
		}
		if (line[len->i] == '$')
			ft_kov_dollar(lisa, line, len);
		if (line[len->i] == len->c)
		{
			len->i++;
			len->flag = 0;
			break ;
		}
		if (line[len->i] && line[len->i] != '\\' && line[len->i] != '$')
			len->i++;
	}
}

void	ft_len_kov_2(t_pars *len, char *line)
{
	len->c = line[len->i++];
	while (1)
	{
		len->count++;
		if (line[len->i] == '\0')
		{
			line[len->i++] = len->c;
			line[len->i] = '\0';
			len->flag = 0;
			break ;
		}
		if (line[len->i] == len->c)
		{
			len->i++;
			len->flag = 0;
			break ;
		}
		if (line[len->i])
			len->i++;
	}
}

void	ft_ft_len_kov_pars_1_socr(t_pars *pars, char *line, t_monna *lisa)
{
	if (line[pars->i + 1] == '\"' || line[pars->i + 1] == '$')
	{
		lisa->tokens[pars->word][pars->j++] = line[++pars->i];
		pars->i++;
	}
	else
		lisa->tokens[pars->word][pars->j++] = line[pars->i++];
	if (line[pars->i] == '\\')
		pars->i++;
	pars->count++;
}

void	ft_len_kov_pars_1(t_pars *pars, char *line, t_monna *lisa)
{
	pars->count = 0;
	pars->c = line[pars->i++];
	while (1)
	{
		pars->count++;
		if (line[pars->i] == '\\')
			ft_ft_len_kov_pars_1_socr(pars, line, lisa);
		if (line[pars->i] == '$')
			ft_kov_dollar_pars(lisa, line, pars);
		if (line[pars->i] == pars->c)
		{
			pars->i++;
			pars->flag = 0;
			lisa->flag_block_zvezda = 1;
			lisa->flag_block_operator = 1;
			break ;
		}
		if (line[pars->i] && line[pars->i] != '\\' && line[pars->i] != '$')
			lisa->tokens[pars->word][pars->j++] = line[pars->i++];
	}
}

void	ft_len_kov_pars_2(t_pars *pars, char *line, t_monna *lisa)
{
	pars->count = 0;
	pars->c = line[pars->i++];
	while (1)
	{
		pars->count++;
		if (line[pars->i] == pars->c)
		{
			pars->i++;
			pars->flag = 0;
			lisa->flag_block_zvezda = 1;
			lisa->flag_block_operator = 1;
			break ;
		}
		lisa->tokens[pars->word][pars->j++] = line[pars->i++];
	}
}
