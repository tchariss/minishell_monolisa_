#include "../minishell.h"

void	ft_tochka_zapitaya(t_pars *len, char *line)
{
	len->flag = 0;
	len->i++;
}

void	ft_redirect(t_pars *len, char *line)
{
	len->flag = 0;
	if (line[len->i] == '>')
	{
		if (line[++len->i] == '>')
			len->i++;
	}
	else
	{
		if (line[++len->i] == '<')
			len->i++;
	}
}

int	ft_operator(t_pars *len, char *line)
{
	if (line[len->i] == '&')
	{
		if (line[++len->i] == '&')
		{
			len->i++;
			len->flag = 0;
			return (1);
		}
	}
	else
	{
		len->flag = 0;
		if (line[++len->i] == '|')
		{
			len->i++;
			return (1);
		}
		return (1);
	}
	return (0);
}

void	ft_len_alpha(char *l, t_pars *len, t_monna *lisa)
{
	while (l[len->i] && l[len->i] != ' '
		&& l[len->i] != '\t' && l[len->i] != ';'
		&& l[len->i] != '&' && l[len->i] != '|'
		&& l[len->i] != '>' && l[len->i] != '<')
	{
		len->count = 0;
		if (l[len->i] == '\"')
			ft_len_kov_1(len, l, lisa);
		if (l[len->i] == '\'')
			ft_len_kov_2(len, l);
		if (l[len->i] == '\\')
			ft_ecran(l, len);
		if (l[len->i] == '$')
			ft_kov_dollar(lisa, l, len);
		while (l[len->i] && l[len->i] != '\t' && l[len->i] != ' '
			&& l[len->i] != '\"' && l[len->i] != '\'' && l[len->i] != '\\'
			&& l[len->i] != ';' && l[len->i] != '&' && l[len->i] != '|'
			&& l[len->i] != '>' && l[len->i] != '<' && l[len->i] != '$')
		{
			len->i++;
			len->flag = 0;
		}
	}
}

int	ft_len_words(char *line, t_monna *lisa)
{
	t_pars	len;

	ft_bzero(&len, sizeof(t_pars));
	while (line[len.i])
	{
		len.flag = 1;
		if (line[len.i] == '\t' || line[len.i] == ' ')
			if (!(ft_len_space_tab(line, &len)))
				break ;
		if (line[len.i] == ';')
			ft_tochka_zapitaya(&len, line);
		if (line[len.i] == '|' || line[len.i] == '&')
			ft_operator(&len, line);
		if (line[len.i] == '<' || line[len.i] == '>')
			ft_redirect(&len, line);
		if (line[len.i] != '\t' && line[len.i] != ' '
			&& line[len.i] != ';' && len.flag && line[len.i] != '&'
			&& line[len.i] != '|' && line[len.i] != '<' && line[len.i] != '>')
			ft_len_alpha(line, &len, lisa);
		if (len.flag == 0)
			len.word++;
	}
	return (len.word);
}
