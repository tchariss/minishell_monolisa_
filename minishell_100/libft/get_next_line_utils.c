/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahmed <Ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:31:45 by tchariss          #+#    #+#             */
/*   Updated: 2021/04/12 13:52:42 by Ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	norm_three_g(char **next_line, char **static_memory, char **line)
{
	*next_line = ft_strchr(*static_memory, '\n');
	if (*next_line)
	{
		**next_line = '\0';
		*line = ft_strdup(*static_memory);
		if (!(*line))
			return (-1);
		ft_strcopy(*static_memory, ++(*next_line));
		return (1);
	}
	*line = ft_strdup(*static_memory);
	if (!(*line))
		return (-1);
	return (0);
}

char	*ft_strcopy(char *s1, const char *s2)
{
	while (*s2 != '\0')
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return (s1);
}
