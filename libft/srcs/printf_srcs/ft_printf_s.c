/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:48:06 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 15:50:34 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"
#include "printf_srcs.h"
#include "str.h"

static int	ft_printf_s_rest(int *info)
{
	if (info[1] == -1)
		return (ft_printnchar(info[5] - info[6], ' '));
	else
		return (ft_printnchar(info[5] - info[6], '0'));
}

int			ft_printf_s(va_list ap, int *info)
{
	char		*str;
	int			len;
	int			count;

	if (info[7] == 4)
		return (ft_printf_ms(ap, info));
	str = va_arg(ap, char*);
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	if (info[6] == -1 || info[6] > len)
		info[6] = len;
	if (info[2] == -1)
		count = ft_printf_s_rest(info);
	if (!str && info[1] == -1)
		write(1, "(null)", info[6]);
	else
		write(1, str, info[6]);
	if (info[2] != -1)
		count = ft_printf_s_rest(info);
	return (info[6] + count);
}
