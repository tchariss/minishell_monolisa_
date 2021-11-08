#include "../minishell.h"

void	ft_ecran(char *line, t_pars *len)
{
	if (line[++len->i] != '\0' && line[len->i] != '\t')
	{
		len->i++;
		len->flag = 0;
	}
}

int	ft_zvezda_konec(char *str, char *dir_name, int *flag)
{
	int	i;

	i = *flag;
	while (str[i] == '*')
		i++;
	if (ft_zvezda_konec_2(i, str, dir_name))
		return (1);
	return (0);
}

int	ft_zvezda_seredina(char *str, char *dir_name, int *flag)
{
	int	i;
	int	j;

	i = *flag;
	j = 0;
	while (str[i] == '*')
		i++;
	while (str[i] != '*' && str[i] != '\0')
	{
		i++;
		if (str[i] == '*')
			j++;
	}
	if (j == 0)
		return (2);
	while (str[*flag] == '*')
		*flag += 1;
	if (ft_zvezda_seredina_2(str, dir_name, flag))
		return (1);
	return (0);
}
