/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:22:26 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/22 17:46:23 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			a;
	long int	o;

	o = n;
	if (o < 0)
	{
		o = o * -1;
		write(fd, "-", 1);
	}
	a = o % 10 + '0';
	if (o / 10)
		ft_putnbr_fd(o / 10, fd);
	write(fd, &a, 1);
}
