/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:27:44 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:15:30 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
#include "memory.h"
#include "print.h"
#include "str.h"

static int		ft_printf_o_rest(char *str, int *info)
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

int				ft_printf_o(unsigned long long nb, int *info)
{
	int		count;
	char	*str;

	count = 0;
	if (nb == 0 && info[6] == 0 && info[0] == -1)
		return (ft_printnchar(info[5], ' '));
	str = ft_ulltoa_base(nb, 8);
	if (!ft_addncharbefore(info[6] - (int)ft_strlen(str), '0', &str))
		return (0);
	if (info[0] != -1 && str[0] != '0')
	{
		if (!ft_addncharbefore(1, '0', &str))
			return (0);
	}
	if (info[2] == -1)
		count += ft_printf_o_rest(str, info);
	ft_putstr(str);
	count += (int)ft_strlen(str);
	if (info[2] != -1)
		count += ft_printf_o_rest(str, info);
	ft_strdel(&str);
	return (count);
}
