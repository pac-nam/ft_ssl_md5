/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:24:41 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:06:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversion.h"
#include "memory.h"
#include "print.h"
#include "printf_srcs.h"
#include "str.h"

static int	ft_printf_mc_rest(int *info, int len)
{
	if (info[1] == -1)
		return (ft_printnchar(info[5] - len, ' '));
	else
		return (ft_printnchar(info[5] - len, '0'));
}

int			ft_printf_mc(va_list ap, int *info)
{
	int			count;
	int			len;
	wchar_t		c;
	char		*str;

	count = 0;
	c = va_arg(ap, wchar_t);
	len = ft_strlenwcs(&c);
	if (!(str = (char*)malloc(len + 1)))
		return (0);
	str[len] = '\0';
	len = ft_wc_convert(str, c);
	if (info[2] == -1)
		count += ft_printf_mc_rest(info, len);
	count += write(1, str, len);
	if (info[2] != -1)
		count += ft_printf_mc_rest(info, len);
	ft_strdel(&str);
	return (count);
}
