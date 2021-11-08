#include "../minishell.h"

void	ft_redirect_pars(t_pars *len, t_monna *lisa, char *line)
{
	len->flag = 0;
	if (line[len->i] == '>')
	{
		lisa->tokens[len->word][len->j++] = line[len->i++];
		if (line[len->i] == '>')
			lisa->tokens[len->word][len->j++] = line[len->i++];
	}
	else
	{
		lisa->tokens[len->word][len->j++] = line[len->i++];
		if (line[len->i] == '<')
			lisa->tokens[len->word][len->j++] = line[len->i++];
	}
}

int	ft_memory_pars(t_monna *l, char *line, t_pars *pars)
{
	int	i;

	i = 0;
	l->tokens = (char **)malloc(sizeof(char *) * (ft_len_words(line, l) + 1));
	if (l->tokens == NULL)
		return (0);
	l->tokens[ft_len_words(line, l)] = NULL;
	while (i < ft_len_words(line, l))
	{
		l->tokens[i] = (char *)malloc(sizeof(char) * 1000);
		if (l->tokens[i] == NULL)
			return (0);
		i++;
	}
	if (ft_len_words(line, l) == 0)
		l->tokens[i] = NULL;
	pars->i = 0;
	pars->word = -1;
	return (1);
}

void	ft_operator_pars(t_pars *pars, char *line, t_monna *lisa)
{
	if (line[pars->i] == '&')
	{
		if (line[pars->i + 1] == '&')
		{
			lisa->tokens[pars->word][pars->j++] = line[pars->i++];
			lisa->tokens[pars->word][pars->j++] = line[pars->i++];
			pars->flag = 0;
			return ;
		}
		pars->i++;
	}
	else
	{
		pars->flag = 0;
		if (line[pars->i + 1] == '|')
		{
			lisa->tokens[pars->word][pars->j++] = line[pars->i++];
			lisa->tokens[pars->word][pars->j++] = line[pars->i++];
			return ;
		}
		lisa->tokens[pars->word][pars->j++] = line[pars->i++];
	}
}

void	ft_len_alpha_pars(char *line, t_pars *pars, t_monna *lisa)
{
	while (line[pars->i] && (line[pars->i] != ' '
			&& line[pars->i] != '\t' && line[pars->i] != ';'
			&& line[pars->i] != '&' && line[pars->i] != '|'
			&& line[pars->i] != '>' && line[pars->i] != '<'))
	{
		if (line[pars->i] == '\"')
			ft_len_kov_pars_1(pars, line, lisa);
		if (line[pars->i] == '\'')
			ft_len_kov_pars_2(pars, line, lisa);
		if (line[pars->i] == '$')
			ft_kov_dollar_pars(lisa, line, pars);
		if (line[pars->i] == '\\')
			ft_ecran_pars(pars, line, lisa);
		while (line[pars->i] && line[pars->i] != ' ' && line[pars->i] != '\t'
			&& line[pars->i] != '\"' && line[pars->i] != '\''
			&& line[pars->i] != '\\' && line[pars->i] != ';'
			&& line[pars->i] != '&' && line[pars->i] != '|'
			&& line[pars->i] != '>' && line[pars->i] != '<'
			&& line[pars->i] != '$')
		{
			lisa->tokens[pars->word][pars->j++] = line[pars->i++];
			pars->flag = 0;
		}
	}
}

int	parser(char *line, t_monna *lisa, t_pars *p)
{
	if (ft_memory_pars(lisa, line, p) == 0)
		return (0);
	while (++p->word < ft_len_words(line, lisa) && line[p->i])
	{
		ft_init_pars(lisa, p);
		while (line[p->i] && p->flag)
		{
			if (line[p->i] == '\t' || line[p->i] == ' ')
				if (!(ft_len_space_tab(line, p)))
					break ;
			if (line[p->i] != '\t' && line[p->i] != ' ' && line[p->i] != ';'
				&& line[p->i] != '&' && line[p->i] != '|')
				ft_len_alpha_pars(line, p, lisa);
			if ((line[p->i] == '|' || line[p->i] == '&') && p->flag)
				ft_operator_pars(p, line, lisa);
			if ((line[p->i] == '<' || line[p->i] == '>') && p->flag)
				ft_redirect_pars(p, lisa, line);
			if (line[p->i] == ';' && p->flag)
				ft_tochka_zapitaya_pars(p, line, lisa);
		}
		lisa->tokens[p->word][p->j] = '\0';
		ft_zvezda_epta(lisa, p->word);
		ft_block_operator(lisa, p->word);
	}
	return (1);
}
