#include "../minishell.h"

void	err_num_arg(t_monna *lisa, char *str)
{
	printf("Monolisa: exit: %s: numeric argument required\n", str);
	exit(255);
}

int	boss_atoi(t_monna *lisa, int *count, char *str)
{
	int					i;
	int					b;
	unsigned long long	res;

	i = 0;
	res = 0;
	b = 1;
	if (str[i] == '-')
		b = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		return (0);
	while (str[i] >= 48 && str[i] <= 57 && ft_isdigit(str[i]) == 1)
		res = res * 10 + (str[i++] - '0');
	if (res > 9223372036854775807)
		err_num_arg(lisa, lisa->tokens[*count]);
	return (res * b);
}

int	boss_isdigit(char *s)
{
	int	c;

	c = 0;
	if (s[c] == 43 || s[c] == 45)
		c++;
	while (s[c])
	{
		if (ft_isdigit(s[c]) != 1)
			return (-1);
		c++;
	}
	return (0);
}

int	ft_lenstr(char **mas)
{
	int	i_c;
	int	i;

	i_c = 0;
	i = 0;
	while (mas[i][i_c])
	{
		if (boss_isdigit(mas[i]) == -1)
			return (-1);
		i_c++;
	}
	if (mas[i + 1] && ft_operators_2(mas[i + 1]))
		return (-2);
	return (i);
}

int	ft_exit(t_monna *lisa, int *count)
{
	int		i;
	char	**vika;

	i = 0;
	*count += 1;
	write(1, "exit\n", 5);
	vika = ft_copy_massive(lisa, *count);
	if (!vika[0])
	{
		ft_free_mass(vika);
		free_all_2(NULL, lisa);
		exit(EXIT_SUCCESS);
	}
	if (ft_lenstr(vika) == -1)
		err_num_arg(lisa, vika[0]);
	if (ft_lenstr(vika) == -2)
		err_many_arg(lisa);
	else
		exit((boss_atoi(lisa, count, lisa->tokens[*count])) % 256);
	while (lisa->tokens[*count])
		*count += 1;
	lisa->flag_command = 0;
	lisa->flag_error = 1;
	return (0);
}
