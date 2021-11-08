#include "../minishell.h"

void	err_cd(t_monna *lisa, int *count)
{
	struct stat	status;

	if (stat(lisa->tokens[*count], &status) == 0)
		printf("Monnalisa: cd: %s: Not a directory\n", lisa->tokens[*count]);
	else
		printf("Monnalisa: cd: %s: No such file or directory\n",
			lisa->tokens[*count]);
}

int	search_home(t_monna *lisa)
{
	int	i;
	int	j;

	i = 0;
	while (lisa->my_env[i])
	{
		if (!ft_strncmp(lisa->my_env[i], "HOME=", 5))
		{
			chdir(lisa->my_env[i] + 5);
			j = 0;
			while (lisa->my_env[j])
			{
				if (!ft_strncmp(lisa->my_env[j], "PWD=", 4))
				{
					free (lisa->my_env[j]);
					lisa->my_env[j] = ft_strjoin("PWD=", lisa->my_env[i] + 5);
				}
				j++;
			}
			return (0);
		}
		i++;
	}
	printf("Monnalisa: cd: HOME not set\n");
	return (1);
}

void	go_change_pat_pwd(t_monna *lisa, char *s)
{
	int	i;

	i = 0;
	s = getcwd(NULL, 0);
	while (lisa->my_env[i])
	{
		if (ft_strncmp(lisa->my_env[i], "PWD=", 4) == 0)
		{
			free(lisa->my_env[i]);
			lisa->my_env[i] = ft_strjoin("PWD=", s);
			free(s);
		}
		i++;
	}
}

void	change_oldpwd(t_monna *lisa, char *cur_k)
{
	int		i;
	char	*old;

	i = 0;
	while (lisa->my_env[i])
	{
		if (ft_strncmp(lisa->my_env[i], "OLDPWD=", 7) == 0)
		{
			free(lisa->my_env[i]);
			lisa->my_env[i] = ft_strjoin("OLDPWD=", cur_k);
			return ;
		}
		i++;
	}
	old = ft_strjoin("OLDPWD=", cur_k);
	ft_copy_massive_env(lisa, old);
	if (old)
		free (old);
}

int	ft_cd(t_monna *lisa, int *count)
{
	char	*s;
	char	*cur_k;

	*count += 1;
	if (search_arg(lisa, count) == 0)
		search_home(lisa);
	else if (chdir(lisa->tokens[*count]) == 0)
	{
		cur_k = getcwd(NULL, 0);
		s = ft_strdup(lisa->tokens[*count]);
		go_change_pat_pwd(lisa, s);
		change_oldpwd(lisa, cur_k);
	}
	else
		err_cd(lisa, count);
	lisa->flag_command = 0;
	while (lisa->tokens[*count] && ft_operators_2(lisa->tokens[*count]) != 0)
		*count += 1;
	lisa->flag_error = 0;
	return (0);
}
