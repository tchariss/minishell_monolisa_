/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:32:34 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/25 14:15:25 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	len;

	len = ft_strlen(dst);
	b = len;
	a = 0;
	if (dstsize <= len)
	{
		return (dstsize + ft_strlen(src));
	}
	if (dstsize > 0)
	{
		while (src[a] != '\0' && len < dstsize - 1)
		{
			dst[len] = src[a];
			len++;
			a++;
		}
		dst[len] = '\0';
	}
	return (b + ft_strlen(src));
}
