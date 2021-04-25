/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:02:36 by tchariss          #+#    #+#             */
/*   Updated: 2021/04/11 17:50:09 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	a;

	a = 0;
	p = (char *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	while (a < count * size)
	{
		p[a] = '\0';
		a++;
	}
	return (p);
}
