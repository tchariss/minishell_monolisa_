#include "../minishell.h"

void	err_uns(t_monna *lisa, char *s)
{
	printf("Monnalisa: unset: `%s': not a valid identifier\n", s);
}

void	ft_konec(t_monna *lisa, char *str, t_unset *set)
{
	char	*ok;

	while (lisa->my_env[set->i])
	{
		ok = ft_strjoin(str, "=");
		if (!ft_strcmp(lisa->my_env[set->i], str)
			|| !ft_strncmp(lisa->my_env[set->i], ok, ft_strlen(ok)))
		{
			set->i++;
			free (ok);
			continue ;
		}
		free (ok);
		set->new_mas[set->k] = ft_strdup(lisa->my_env[set->i]);
		set->i++;
		set->k++;
	}
}

int	delete_per(t_monna *lisa, char *str)
{
	t_unset	set;

	ft_bzero(&set, sizeof(t_unset));
	while (lisa->my_env[set.b])
		set.b++;
	set.new_mas = (char **)malloc(sizeof(char *) * (set.b + 1));
	if (set.new_mas == 0)
		return (0);
	set.k = 0;
	ft_konec(lisa, str, &set);
	set.new_mas[set.k] = NULL;
	if (lisa->my_env)
		ft_free_mass(lisa->my_env);
	lisa->my_env = set.new_mas;
	return (1);
}

int	ft_unset(t_monna *lisa, int *count)
{
	*count += 1;
	if (!lisa->tokens[*count])
		return (0);
	while (lisa->tokens[*count] && ft_operators(lisa->tokens[*count]))
	{
		if (srch_null_arg(*lisa->tokens[*count]) == 0
			|| ft_strchr(lisa->tokens[*count], '=') != NULL)
			err_uns(lisa, lisa->tokens[*count]);
		else
			delete_per(lisa, lisa->tokens[*count]);
		*count += 1;
	}
	lisa->flag_command = 0;
	while (lisa->tokens[*count] && ft_operators_2(lisa->tokens[*count]))
		*count += 1;
	lisa->flag_error = 0;
	return (0);
}
