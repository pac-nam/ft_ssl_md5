/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:01 by tbleuse           #+#    #+#             */
/*   Updated: 2019/01/10 12:02:56 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"

/*
**	print the number nb on the file descriptor fd.
*/

static int	ft_special_putnbr(int nb, int fd)
{
	if (nb > -1 && nb < 10)
	{
		ft_putchar_fd(nb + 48, fd);
		return (1);
	}
	else if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void		ft_putnbr_fd(int nb, int fd)
{
	char	str[11];
	int		nb2;
	int		len;
	int		len_to_write;

	if (ft_special_putnbr(nb, fd))
		return ;
	len = 0;
	if (nb < 0)
	{
		str[len++] = '-';
		nb = -nb;
	}
	nb2 = nb;
	while ((nb2 = nb2 / 10))
		++len;
	len_to_write = len + 1;
	while (nb != 0)
	{
		str[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	write(fd, str, len_to_write);
}
