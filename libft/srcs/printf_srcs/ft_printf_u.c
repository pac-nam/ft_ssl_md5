/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:28:56 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:16:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
#include "memory.h"
#include "print.h"
#include "str.h"

static int		ft_printf_u_rest(char *str, int *info)
{
	int		len;

	len = (int)ft_strlen(str);
	if (info[5] > len)
	{
		if (info[1] == -1)
			ft_printnchar(info[5] - len, ' ');
		if (info[1] != -1)
			ft_printnchar(info[5] - len, '0');
		return (info[5] - len);
	}
	return (0);
}

int				ft_printf_u(unsigned long long nb, int *info)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_ulltoa_base(nb, 10);
	if (*str == '0' && info[6] == 0)
	{
		count += ft_printnchar(info[5], ' ');
		ft_strdel(&str);
		return (count);
	}
	if (!ft_addncharbefore(info[6] - (int)ft_strlen(str), '0', &str))
		return (0);
	if (info[2] == -1)
		count += ft_printf_u_rest(str, info);
	ft_putstr(str);
	count += (int)ft_strlen(str);
	if (info[2] != -1)
		count += ft_printf_u_rest(str, info);
	ft_strdel(&str);
	return (count);
}
