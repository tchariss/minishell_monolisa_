/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:32:16 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/20 13:20:20 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr1;
	size_t	a;

	a = 0;
	ptr1 = (char *)s;
	while (a < n)
	{
		if (ptr1[a] == c)
			return ((char *)s + a);
		a++;
	}
	return (NULL);
}
