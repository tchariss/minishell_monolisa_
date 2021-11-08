/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:14:26 by tchariss          #+#    #+#             */
/*   Updated: 2021/06/12 22:02:46 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_gnl
{
	char	buf[BUFFER_SIZE + 2];
	char	*ukaz_n;
}				t_gnl;

typedef struct s_gnl2
{
	int			sym;
	int			check;
}				t_gnl2;

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcopy(char *s1, const char *s2);
int		norm_three_g(char **next_line, char **static_memory, char **line);

#endif
