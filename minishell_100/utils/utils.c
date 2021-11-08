#include "../minishell.h"

int	ft_lenmassive(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_list_clear(t_list **head)
{
	t_list	*tmp;
	t_list	*list;

	list = *head;
	tmp = NULL;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(list->content);
		free(list);
		list = tmp;
	}
}

int	ft_boss_reg(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i]
		&& (unsigned char)ft_tolower(s1[i])
		== (unsigned char)ft_tolower(s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	tfy_ti_arg(t_monna *l, char *s)
{
	int	i;

	i = 0;
	if (srch_null_arg(s[0]) == 0)
		return (2);
	while (s[i])
	{
		if (srch_next_arg(s[i]) == 0)
			return (2);
		i++;
	}
	return (0);
}
