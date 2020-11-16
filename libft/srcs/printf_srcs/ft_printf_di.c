/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:25:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 15:53:20 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversion.h"
#include "memory.h"
#include "print.h"
#include "str.h"

static int		ft_printf_di_zero(char **str, int *info)
{
	int		count;

	if (info[3] == 1 || info[4] == 1)
		info[5] -= 1;
	count = 0;
	if (info[2] == -1)
		count += ft_printnchar(info[5], ' ');
	if (info[3] == 1)
		count += write(1, "+", 1);
	else if (info[4] == 1)
		count += write(1, " ", 1);
	if (info[2] != -1)
		count += ft_printnchar(info[5], ' ');
	ft_strdel(str);
	return (count);
}

static int		ft_modif_nb(char **str, int **info)
{
	char	*tmp;

	if ((*str)[0] == '-' || (*info)[3] == 1 || (*info)[4] == 1)
		(*info)[0] = 1;
	if ((*str)[0] == '-')
	{
		tmp = *str;
		if (!(*str = ft_strdup(&((*str)[1]))))
			return (0);
		(*info)[7] = -2;
		ft_strdel(&tmp);
	}
	if (!(ft_addncharbefore((*info)[6] - (int)ft_strlen(*str), '0', str)))
		return (0);
	(*info)[6] = (int)ft_strlen(*str);
	if ((*info)[1] == 1)
	{
		if (!(ft_addncharbefore((*info)[5] - (*info)[6], '0', str)))
			return (0);
		if ((*info)[5] > (*info)[6])
			(*info)[5] = -2;
	}
	return (1);
}

static int		ft_printf_di_second(char **str, int *info)
{
	int		count;

	count = 0;
	if (info[2] == -1 && info[1] == -1)
		count += ft_printnchar(info[5] - info[6] - info[0], ' ');
	if (info[3] == 1 && info[7] != -2)
		count += write(1, "+", 1);
	else if (info[4] == 1 && info[7] != -2)
		count += write(1, " ", 1);
	else if (info[7] == -2)
		count += write(1, "-", 1);
	if (info[5] == -2 && count != 0)
	{
		ft_putstr(*str + 1);
		--count;
	}
	else
		ft_putstr(*str);
	count += (int)ft_strlen(*str);
	if (info[2] != -1)
		count += ft_printnchar(info[5] - count, ' ');
	ft_strdel(str);
	return (count);
}

int				ft_printf_di(va_list ap, int *info)
{
	char	*str;

	info[0] = 0;
	if (info[7] == 0)
		str = ft_itoa(va_arg(ap, int));
	if (info[7] == 1)
		str = ft_lltoa((long long)(signed char)va_arg(ap, int));
	if (info[7] == 2)
		str = ft_lltoa((long long)(short)va_arg(ap, int));
	if (info[7] == 3)
		str = ft_lltoa((long long)va_arg(ap, long));
	if (info[7] == 4)
		str = ft_lltoa((long long)va_arg(ap, long long));
	if (info[7] == 5)
		str = ft_lltoa((long long)(intmax_t)va_arg(ap, long long));
	if (info[7] == 6)
		str = ft_lltoa((long long)va_arg(ap, unsigned long long));
	if (str[0] == '0' && info[6] == 0)
		return (ft_printf_di_zero(&str, info));
	if (!str || !(ft_modif_nb(&str, &info)))
		return (0);
	return (ft_printf_di_second(&str, info));
}
