#include "../minishell.h"

void	ft_tochka(t_monna *lisa, int *count)
{
	lisa->flag_red_files = 0;
	count += 1;
}

void	ft_else(t_monna *lisa, int *count)
{
	lisa->flag_command = ft_any_argument(lisa, count);
	lisa->flag_error = lisa->flag_command;
}

int	len_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

void	err_exp(t_monna *lisa, char *s)
{
	printf("Monnalisa: export: `%s': not a valid identifier\n", s);
}

int	srch_next_arg(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c == 95) || (c == 61))
		return (1);
	else
		return (0);
}
