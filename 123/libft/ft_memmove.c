/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:32:25 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/20 13:18:33 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			a;
	unsigned char	*d;
	unsigned char	*s;

	a = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (src == dst)
		return (d);
	if (d > s)
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	else
	{
		while (a < len)
		{
			d[a] = s[a];
			a++;
		}
	}
	return (d);
}
