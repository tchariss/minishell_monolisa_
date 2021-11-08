/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:30:26 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/20 13:18:19 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr1;
	size_t	a;

	a = 0;
	ptr1 = (char *)b;
	while (a < len)
	{
		*(ptr1 + a) = c;
		a++;
	}
	return (b);
}
