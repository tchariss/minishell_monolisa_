/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:02:01 by tchariss          #+#    #+#             */
/*   Updated: 2021/04/11 17:49:09 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	if (ft_strlen(needle) == 0)
	{
		return ((char *)haystack);
	}
	while (a < len && haystack[a] != '\0')
	{
		b = 0;
		c = a;
		while (needle[b] == haystack[c] && c < len && needle[b] != '\0')
		{
			c++;
			b++;
		}
		if (needle[b] == '\0')
		{
			return ((char *)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
