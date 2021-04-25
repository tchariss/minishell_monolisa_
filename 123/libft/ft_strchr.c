/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:02:19 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/20 13:13:45 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (c == '\0')
	{
		while (s[a] != '\0')
			a++;
		return ((char *)&s[a]);
	}
	while (s[a] != '\0')
	{
		if (s[a] == c)
			return ((char *)&s[a]);
		a++;
	}
	return (0);
}
