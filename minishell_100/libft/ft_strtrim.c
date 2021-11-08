/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:21:31 by tchariss          #+#    #+#             */
/*   Updated: 2021/04/11 17:47:13 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search(const char *set, char sym)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == sym)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	len;
	size_t	b;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	b = 0;
	a = 0;
	while (search(set, s1[len - 1]) == 1)
		len--;
	if (len > 0)
	{
		while (search(set, s1[a]) == 1 && s1[a] != '\0')
			a++;
	}
	trim = malloc(sizeof(char) * ((len - a) + 1));
	if (!(trim))
		return (NULL);
	while (a < len)
		trim[b++] = s1[a++];
	trim[b] = '\0';
	return (trim);
}
