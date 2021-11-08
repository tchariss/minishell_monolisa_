#include "../minishell.h"

void	ft_dollar_ili_net(t_monna *l, t_pars *len)
{
	int	i;

	i = 0;
	while (l->my_env[i])
	{
		if (!(ft_strncmp(l->tmp_env, l->my_env[i], ft_strlen(l->tmp_env))))
		{
			len->count++;
			len->flag = 0;
			return ;
		}
		i++;
	}
}

void	ft_dollar_ili_net_pars(t_monna *l, t_pars *pars)
{
	int	i;
	int	y;

	i = 0;
	while (l->my_env[i])
	{
		if (!(ft_strncmp(l->tmp_env, l->my_env[i], ft_strlen(l->tmp_env))))
		{
			y = 0;
			while (l->my_env[i][y] != '=')
				y++;
			y++;
			while (l->my_env[i][y])
			{
				l->tokens[pars->word][pars->j] = l->my_env[i][y];
				pars->j++;
				y++;
				pars->flag = 0;
			}
			return ;
		}
		i++;
	}
}

void	ft_kov_dollar(t_monna *lisa, char *line, t_pars *len)
{
	int	tmp;

	tmp = 0;
	ft_clean_tmp_env(lisa);
	if (!(ft_isalnum(line[len->i + 1])) && line[len->i + 1] != '?')
	{
		len->i += 2;
		len->count++;
		len->flag = 0;
		return ;
	}
	if (proverka_isdigit(line, len))
		return ;
	if (line[len->i + 1] == '?')
	{
		len->i += 2;
		len->count++;
		len->flag = 0;
		return ;
	}
	while (ft_isalnum(line[++len->i]) || line[len->i] == '_')
		lisa->tmp_env[tmp++] = line[len->i];
	lisa->tmp_env[tmp] = '=';
	ft_dollar_ili_net(lisa, len);
}

void	ft_ft_kov_dollar_pars_socr(t_monna *li, t_pars *len, int l, char *str)
{
	len->i++;
	str = ft_itoa(li->flag_error);
	while (str[l])
		li->tokens[len->word][len->j++] = str[l++];
	len->i++;
	len->flag = 0;
}

void	ft_kov_dollar_pars(t_monna *lisa, char *line, t_pars *len)
{
	char	*str;
	int		tmp;
	int		l;

	l = 0;
	tmp = 0;
	ft_clean_tmp_env(lisa);
	if (!(ft_isalnum(line[len->i + 1])) && line[len->i + 1] != '?')
	{
		lisa->tokens[len->word][len->j++] = line[len->i++];
		lisa->tokens[len->word][len->j++] = line[len->i++];
		len->flag = 0;
		return ;
	}
	if (proverka_isdigit(line, len))
		return ;
	if (line[len->i + 1] == '?')
	{
		ft_ft_kov_dollar_pars_socr(lisa, len, l, str);
		return ;
	}
	while (ft_isalnum(line[++len->i]) || line[len->i] == '_')
		lisa->tmp_env[tmp++] = line[len->i];
	lisa->tmp_env[tmp] = '=';
	ft_dollar_ili_net_pars(lisa, len);
}
