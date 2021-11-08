/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:32:30 by tchariss          #+#    #+#             */
/*   Updated: 2021/04/11 17:48:57 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	char	*s1;
	size_t	len;

	a = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	s1 = malloc(sizeof(char) * len + 1);
	if (!(s1))
		return (NULL);
	while (s[a] != '\0')
	{
		s1[a] = f(a, s[a]);
		a++;
	}
	s1[a] = '\0';
	return (s1);
}
