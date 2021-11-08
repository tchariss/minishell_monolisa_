#include "../minishell.h"

void	ft_ecran_pars(t_pars *pars, char *line, t_monna *lisa)
{
	if (line[++pars->i] != '\0' && line[pars->i] != '\t')
	{
		pars->flag = 0;
		lisa->tokens[pars->word][pars->j++] = line[pars->i++];
		lisa->flag_block_zvezda = 1;
		lisa->flag_block_operator = 1;
	}
}

void	ft_block_operator(t_monna *lisa, int nomer_ukaza)
{
	int	i;

	i = 0;
	while (lisa->tokens[nomer_ukaza][i])
		i++;
	i++;
	if (lisa->flag_block_operator == 1)
		lisa->tokens[nomer_ukaza][i] = 1;
	else
		lisa->tokens[nomer_ukaza][i] = 0;
}

void	ft_tochka_zapitaya_pars(t_pars *pars, char *line, t_monna *lisa)
{
	lisa->tokens[pars->word][pars->j++] = line[pars->i++];
	pars->flag = 0;
}

char	*del_start_space(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strdup(line);
	if (tmp == NULL)
		return (NULL);
	free (line);
	while (tmp[i] == ' ' || tmp[i] == '\t')
		i++;
	line = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 1 - i);
	if (line == NULL)
		return (NULL);
	while (tmp[i])
		line[j++] = tmp[i++];
	line[j] = tmp[i];
	free (tmp);
	if (line [0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}
