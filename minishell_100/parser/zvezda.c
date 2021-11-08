#include "../minishell.h"

int	ft_zvezda_nachalo(char *str, char *dir_name, int *flag)
{
	int	j;

	j = 0;
	while (str[*flag] != '*')
		*flag += 1;
	if (ft_zvezda_nachalo_2(*flag, str, dir_name))
		return (1);
	return (0);
}

int	ft_zvezda_v_shoke(char *str, char *dir_name)
{
	t_vshoke	sh;

	sh.flag = 0;
	if (str[sh.flag] && str[sh.flag] != '*')
	{
		sh.a = ft_zvezda_nachalo(str, dir_name, &sh.flag);
		if (sh.a == 0)
			return (0);
	}
	if (str[sh.flag] == '*')
	{
		while (1)
		{
			sh.a = ft_zvezda_seredina(str, dir_name, &sh.flag);
			if (sh.a == 0)
				return (0);
			if (sh.a == 2)
				break ;
		}
	}
	if (str[sh.flag] == '*' && str[ft_strlen(str) - 1] != '*')
		if (!ft_zvezda_konec(str, dir_name, &sh.flag))
			return (0);
	return (1);
}

void	ft_zvezda_epta_pt1(t_ept *pt, t_vshoke *sh, t_monna *lisa, int num)
{
	while (1)
	{
		pt->myfile = readdir(pt->mydir);
		if (pt->myfile == NULL)
			break ;
		sh->x = 0;
		stat(pt->myfile->d_name, &pt->mystat);
		if (pt->myfile->d_name[0] == '.')
			continue ;
		while (pt->myfile->d_name[sh->x])
			lisa->tokens[num][sh->j++] = pt->myfile->d_name[sh->x++];
		lisa->tokens[num][sh->j++] = ' ';
	}
	lisa->tokens[num][sh->j - 1] = '\0';
	closedir(pt->mydir);
}

void	ft_zvezda_epta_pt2(t_ept *pt, t_vshoke *sh, t_monna *lisa, int num)
{
	sh->count = 0;
	while (1)
	{
		pt->myfile = readdir(pt->mydir);
		if (pt->myfile == NULL)
			break ;
		sh->x = 0;
		stat(pt->myfile->d_name, &pt->mystat);
		if (pt->myfile->d_name[0] == '.')
			continue ;
		if (ft_zvezda_v_shoke(lisa->tmp_env, pt->myfile->d_name))
		{
			while (pt->myfile->d_name[sh->x])
				lisa->tokens[num][sh->j++] = pt->myfile->d_name[sh->x++];
			lisa->tokens[num][sh->j++] = ' ';
			sh->count = 1;
		}
	}
	if (sh->count)
		lisa->tokens[num][sh->j - 1] = '\0';
	closedir(pt->mydir);
}

void	ft_zvezda_epta(t_monna *lisa, int num_u)
{
	t_ept		pt;
	t_vshoke	sh;

	ft_bzero(&sh, sizeof(t_vshoke));
	if (lisa->flag_block_zvezda)
		return ;
	ft_clean_tmp_env(lisa);
	ft_strcpy(lisa->tmp_env, lisa->tokens[num_u]);
	while (lisa->tmp_env[sh.i])
	{
		if (lisa->tmp_env[sh.i] == '*')
			sh.count++;
		sh.i++;
	}
	if (sh.count == 0)
		return ;
	pt.mydir = opendir(".");
	if (sh.i == sh.count)
	{
		ft_zvezda_epta_pt1(&pt, &sh, lisa, num_u);
		return ;
	}
	ft_zvezda_epta_pt2(&pt, &sh, lisa, num_u);
}
