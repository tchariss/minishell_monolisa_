#include "../minishell.h"

int	ft_zvezda_konec_2(int i, char *str, char *dir_name)
{
	char	*tmp;
	int		x;

	x = 0;
	tmp = (char *)malloc(sizeof(char) * 100);
	if (!tmp)
		return (0);
	while (str[i])
		tmp[x++] = str[i++];
	tmp[x] = '\0';
	x = ft_strlen(dir_name) - ft_strlen(tmp);
	i = 0;
	while (tmp[i])
	{
		if (x < 0 || tmp[i] - dir_name[x] != 0)
		{
			free (tmp);
			return (0);
		}
		i++;
		x++;
	}
	free (tmp);
	return (1);
}

int	ft_zvezda_seredina_2(char *str, char *dir_name, int *flag)
{
	char	*tmp;
	int		x;
	int		i;

	tmp = (char *)malloc(sizeof(char) * 100);
	if (!tmp)
		return (0);
	x = 0;
	while (str[*flag] != '*')
	{
		tmp[x] = str[*flag];
		x++;
		*flag += 1;
	}
	tmp[x] = '\0';
	i = 0;
	if (ft_strstr(dir_name, tmp))
	{
		free (tmp);
		return (1);
	}
	free (tmp);
	return (0);
}

int	ft_zvezda_nachalo_2(int i, char *str, char *dir_name)
{
	if (ft_strncmp(str, dir_name, i))
		return (0);
	return (1);
}
