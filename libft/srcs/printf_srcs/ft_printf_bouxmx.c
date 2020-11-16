/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bouxmx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:52:07 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:40:18 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "printf_srcs.h"

static int		ft_printf_bouxmx_second(unsigned long long nb, int *info)
{
	if (info[9] == (int)'o')
		return (ft_printf_o(nb, info));
	if (info[9] == (int)'u')
		return (ft_printf_u(nb, info));
	if (info[9] == (int)'x')
		return (ft_printf_x(nb, info));
	if (info[9] == (int)'X')
		return (ft_printf_mx(nb, info));
	if (info[9] == (int)'b')
		return (ft_printf_b(nb, info));
	return (0);
}

int				ft_printf_bouxmx(va_list ap, int *info)
{
	unsigned long long	nb;

	if (info[7] == 0)
		nb = (unsigned long long)(va_arg(ap, unsigned int));
	if (info[7] == 1)
		nb = (unsigned long long)(unsigned char)va_arg(ap, int);
	if (info[7] == 2)
		nb = (unsigned long long)(unsigned short)va_arg(ap, int);
	if (info[7] == 3)
		nb = (unsigned long long)va_arg(ap, long);
	if (info[7] == 4)
		nb = (unsigned long long)va_arg(ap, long long);
	if (info[7] == 5)
		nb = (unsigned long long)(uintmax_t)va_arg(ap, long long);
	if (info[7] == 6)
		nb = (unsigned long long)va_arg(ap, unsigned long long);
	return (ft_printf_bouxmx_second(nb, info));
}
