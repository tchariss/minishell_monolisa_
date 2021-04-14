/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:32:09 by tchariss          #+#    #+#             */
/*   Updated: 2021/04/11 20:15:21 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int	free_gnl(t_gnl **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}

int	proverka_static_memory(char *static_memory, char **line)
{
	char	*next_line;

	next_line = NULL;
	if (static_memory != NULL)
		return (norm_three_g(&next_line, &static_memory, line));
	else
	{
		*line = ft_strdup("");
		if (!(*line))
			return (-1);
	}
	return (0);
}

int	get_line(t_gnl *gnl, char ***line, char **static_memory, int sym)
{
	char	*saveper;

	gnl->buf[sym] = '\0';
	gnl->ukaz_n = ft_strchr(gnl->buf, '\n');
	if (gnl->ukaz_n != NULL)
	{
		*gnl->ukaz_n = '\0';
		*static_memory = ft_strdup(++gnl->ukaz_n);
		if (!(*static_memory))
			return (-1);
	}
	saveper = **line;
	**line = ft_strjoin(**line, gnl->buf);
	if (!(**line))
		return (-1);
	free(saveper);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	t_gnl		*gnl;
	int			sym;
	int			check;
	static char	*static_memory;

	check = 0;
	sym = 0;
	if (line == NULL || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	gnl = (t_gnl *)malloc(sizeof(t_gnl));
	if (!gnl)
		return (-1);
	gnl->ukaz_n = NULL;
	check = proverka_static_memory(static_memory, line);
	if (check == -1)
		return (free_gnl(&gnl));
	if (check != 1)
		free_str(&static_memory);
	while (check == 0 && gnl->ukaz_n == 0
		&& (sym = read(fd, gnl->buf, BUFFER_SIZE)) > 0)
		if (get_line(gnl, &line, &static_memory, sym) == -1)
			return (free_gnl(&gnl));
	free(gnl);
	return ((sym || check));
}
