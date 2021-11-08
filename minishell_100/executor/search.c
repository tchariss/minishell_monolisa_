#include "../minishell.h"

int	ft_search_com(char *str)
{
	if (!(ft_boss_reg(str, "echo")) || !(ft_boss_reg(str, "cd"))
		|| !(ft_boss_reg(str, "pwd")) || !(ft_strcmp(str, "export"))
		|| !(ft_strcmp(str, "unset")) || !(ft_boss_reg(str, "env"))
		|| !(ft_strcmp(str, "exit")))
		return (1);
	return (0);
}

int	ft_operators(char *str)
{
	if ((!(ft_strcmp(str, "&&")) && str[3] == 0)
		|| (!(ft_strcmp(str, "||")) && str[3] == 0)
		|| (!(ft_strcmp(str, "|")) && str[2] == 0)
		|| (!(ft_strcmp(str, ">")) && str[2] == 0)
		|| (!(ft_strcmp(str, "<")) && str[2] == 0)
		|| (!(ft_strcmp(str, ">>")) && str[3] == 0)
		|| (!(ft_strcmp(str, "<<")) && str[3] == 0)
		|| (!(ft_strcmp(str, ";")) && str[2] == 0))
		return (0);
	return (1);
}

int	ft_operators_2(char *str)
{
	if ((!(ft_strcmp(str, "&&")) && str[3] == 0)
		|| (!(ft_strcmp(str, "||")) && str[3] == 0)
		|| (!(ft_strcmp(str, "|")) && str[2] == 0)
		|| (!(ft_strcmp(str, ";")) && str[2] == 0))
		return (0);
	return (1);
}

int	ft_red_serch(char *str)
{
	if ((!(ft_strcmp(str, ">")) && str[2] == 0)
		|| (!(ft_strcmp(str, "<")) && str[2] == 0)
		|| (!(ft_strcmp(str, ">>")) && str[3] == 0)
		|| (!(ft_strcmp(str, "<<")) && str[3] == 0))
		return (1);
	return (0);
}

int	ft_red_serch_2(char *str)
{
	if ((!(ft_strcmp(str, "&&")) && str[3] == 0)
		|| (!(ft_strcmp(str, "|")) && str[2] == 0)
		|| (!(ft_strcmp(str, "||")) && str[3] == 0)
		|| (!(ft_strcmp(str, ";")) && str[2] == 0))
		return (1);
	return (0);
}
