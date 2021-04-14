/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:22:21 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/20 13:14:26 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	full_massiv(char *s1, const char *s2, size_t start, size_t end)
{
	size_t	con;

	con = 0;
	while (start < end)
	{
		s1[con] = s2[start];
		start++;
		con++;
	}
	s1[con] = '\0';
}

void	free_memory(char **list, size_t words)
{
	size_t	n;

	n = 0;
	while (n < words)
	{
		free(list[n]);
		n++;
	}
	free(list);
}

size_t	ft_count(const char *list, char c)
{
	size_t	num;
	size_t	words;

	words = 0;
	num = 0;
	while (list[num] == c && list[num] != '\0')
		num++;
	while (list[num] != '\0')
	{
		while (list[num] != c && list[num] != '\0')
			num++;
		words++;
		while (list[num] == c && list[num] != '\0')
			num++;
	}
	return (words);
}

char	**full_list(const char *s, char c, char **list, size_t num_w)
{
	size_t	numb;
	size_t	words;
	size_t	len_word;

	words = 0;
	numb = 0;
	len_word = 0;
	while (s[numb] != '\0' && num_w > words)
	{
		while (s[numb] == c && s[numb] != '\0')
			numb++;
		len_word = numb;
		while (s[len_word] != c && s[len_word] != '\0')
			len_word++;
		list[words] = (char *)malloc(((len_word - numb) + 1) * sizeof(char));
		if (!list[words])
		{
			free_memory(list, words);
			return (NULL);
		}
		full_massiv(list[words], s, numb, len_word);
		words++;
		numb = len_word;
	}
	return (list);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**list;

	if (!s)
		return (NULL);
	words = ft_count(s, c);
	list = (char **)malloc((words + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	list = full_list(s, c, list, words);
	if (!list)
		return (NULL);
	list[words] = NULL;
	return (list);
}
