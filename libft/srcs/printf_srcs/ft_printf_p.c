/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:28:07 by tbleuse           #+#    #+#             */
/*   Updated: 2018/08/05 12:31:58 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversion.h"
#include "memory.h"
#include "print.h"
#include "str.h"

static int		ft_printf_p_rest(int *info)
{
	if (info[1] == -1)
		return (ft_printnchar(info[5] - info[6], ' '));
	else
		return (ft_printnchar(info[5] - info[6], '0'));
}

static int		ft_printf_p_zero(char **ptr, int *info)
{
	int		count;

	count = 0;
	if (info[6] == -1)
		info[6] = 1;
	if (info[2] == -1 && info[1] == -1)
		count += ft_printnchar(info[5] - info[6] - 2, ' ');
	count += write(1, "0x", 2);
	count += ft_printnchar(info[6], '0');
	if (info[2] == -1 && info[1] != -1)
		count += ft_printnchar(info[5] - info[6] - 2, '0');
	if (info[2] != -1 && info[1] == -1)
		count += ft_printnchar(info[5] - info[6] - 2, ' ');
	ft_strdel(ptr);
	return (count);
}

int				ft_printf_p(va_list ap, int *info)
{
	char		*ptr;
	int			count;

	ptr = ft_ulltoa_base((unsigned long long)va_arg(ap, void*), 16);
	info[0] = ft_strlen(ptr);
	if (*ptr == '0')
		return (ft_printf_p_zero(&ptr, info));
	if (!ft_addncharbefore(info[6] - info[0], '0', &ptr)
			|| !ft_addncharbefore(1, 'x', &ptr)
			|| !ft_addncharbefore(1, '0', &ptr))
		return (0);
	count = 0;
	info[6] = ft_strlen(ptr);
	if (info[2] == -1)
		count += ft_printf_p_rest(info);
	count += write(1, ptr, info[6]);
	if (info[2] != -1)
		count += ft_printf_p_rest(info);
	ft_strdel(&ptr);
	return (count);
}
