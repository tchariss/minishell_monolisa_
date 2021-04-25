/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:22:06 by tchariss          #+#    #+#             */
/*   Updated: 2021/04/11 18:08:11 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	int		a;
	int		b;

	a = -1;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (s1[++a] != '\0')
		str[a] = s1[a];
	while (s2[b] != '\0')
	{
		str[a] = s2[b];
		b++;
		a++;
	}
	str[a] = '\0';
	return (str);
}
