/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:32:18 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/20 13:21:32 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			a;
	unsigned char	*d;
	unsigned char	*s;

	a = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (a < n)
	{
		d[a] = s[a];
		if (s[a] == (unsigned char)c)
			return ((char *)dst + a + 1);
		a++;
	}
	return (0);
}
