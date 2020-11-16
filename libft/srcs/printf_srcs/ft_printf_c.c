/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:41 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:04:04 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"
#include "printf_srcs.h"

static int	ft_printf_c_rest(int *info)
{
	if (info[1] == -1)
		return (ft_printnchar(info[5] - 1, ' '));
	else
		return (ft_printnchar(info[5] - 1, '0'));
}

int			ft_printf_c(va_list ap, int *info)
{
	int		count;
	char	c;

	if (info[7] == 4)
		return (ft_printf_mc(ap, info));
	count = 0;
	c = (char)va_arg(ap, int);
	if (info[2] == -1)
		count += ft_printf_c_rest(info);
	write(1, &c, 1);
	if (info[2] != -1)
		count += ft_printf_c_rest(info);
	return (count + 1);
}
