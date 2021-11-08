/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:02:22 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/23 22:09:34 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;
	int		a;
	int		b;

	a = 0;
	b = 0;
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == 0)
		return (NULL);
	while (s1[a] != '\0')
	{
		s2[b] = s1[a];
		a++;
		b++;
	}
	s2[b] = '\0';
	return (s2);
}
