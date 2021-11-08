#include "../minishell.h"

void	ft_free_mass(char	**mas)
{
	int	i;

	i = 0;
	while (mas[i])
		free (mas[i++]);
	free (mas);
}

void	ft_desert_rose(t_copy_mass *me, int *i, t_monna *lisa)
{
	me->tmp = *i;
	me->j = 0;
	while (lisa->tokens[*i] && ft_operators(lisa->tokens[*i]))
	{
		*i += 1;
		me->j++;
	}
	*i = me->tmp;
	me->str = (char **)malloc(sizeof(char *) * (me->j + 2));
	me->j = 0;
	ft_bzero(me->str, sizeof(char **));
	while (lisa->tokens[*i] && ft_operators(lisa->tokens[*i]))
	{
		me->str[me->j] = ft_strdup(lisa->tokens[*i]);
		me->j++;
		*i += 1;
	}
	me->str[me->j] = NULL;
	me->str[me->j + 1] = NULL;
}

char	**ft_copy_massive(t_monna *lisa, int i)
{
	t_copy_mass	me;

	ft_desert_rose(&me, &i, lisa);
	if (me.str[0] && !ft_strncmp(me.str[0], "./minishell", 11))
	{
		if (me.str[1] == NULL)
		{
			me.str[1] = ft_strdup(ft_itoa(lisa->shell_lvl));
			me.str[2] = NULL;
		}
		else
		{
			free (me.str[1]);
			me.str[1] = ft_strdup(ft_itoa(lisa->shell_lvl));
		}
	}
	if ((me.str[0] && !ft_strcmp(me.str[0], "cat")) && lisa->flag_red_4)
	{
		me.str[me.j] = (char *)malloc(sizeof(char ) * 2);
		me.str[me.j][0] = '1';
		me.str[me.j][1] = '\0';
	}
	return (me.str);
}

int	srch_null_arg(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == 95))
		return (1);
	else
		return (0);
}

int	search_per_env(t_monna *lisa, char *str, int len)
{
	char	*new_s;
	int		i;

	i = 0;
	while (lisa->my_env[i])
	{
		if (ft_strncmp(lisa->my_env[i], str, len) == 0
			|| ft_strncmp(lisa->my_env[i], str, len - 1) == 0)
		{
			free(lisa->my_env[i]);
			lisa->my_env[i] = ft_strdup(str);
			return (0);
		}
		i++;
	}
	return (1);
}
