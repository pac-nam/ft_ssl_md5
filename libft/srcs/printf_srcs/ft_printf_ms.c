/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:48:06 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 15:56:13 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "conversion.h"
#include "print.h"
#include "str.h"

static int		ft_printf_ms_rest(int *info)
{
	if (info[1] == -1)
		return (ft_printnchar(info[5] - info[6], ' '));
	else
		return (ft_printnchar(info[5] - info[6], '0'));
}

int				ft_printf_ms(va_list ap, int *info)
{
	wchar_t		*wcs;
	char		*str;
	int			len;
	int			count;

	count = 0;
	wcs = va_arg(ap, wchar_t*);
	len = ft_strlenwcs(wcs);
	if (info[6] == -1 || info[6] > len)
		info[6] = len;
	if (!(str = (char*)malloc(len + 1)))
		return (0);
	if ((len = ft_wcs_convert(str, wcs, info[6])) == -1)
		return (0);
	if (info[2] == -1)
		count += ft_printf_ms_rest(info);
	str[len] = '\0';
	if (wcs == NULL)
		write(1, "(null)", info[6]);
	else
		write(1, str, ft_strlen(str));
	if (info[2] != -1)
		count += ft_printf_ms_rest(info);
	ft_strdel(&str);
	return (info[6] + count);
}
