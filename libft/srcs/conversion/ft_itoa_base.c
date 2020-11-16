/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:41:34 by exam              #+#    #+#             */
/*   Updated: 2018/03/21 13:56:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"
#include "conversion.h"

/*
**	ft_itoa_base return a string containing the value passed in parameter
**	in the base also passed in parametre.
**	If value is less than 0 and base is not 10, 0 is returned.
**	If value base is less 2 or more than 16, 0 is returned too.
**	WARNING: ft_itoa use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

static char	*ft_special_itoa(int base)
{
	if (base == 10)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char		*ft_itoa_base(int value, int base)
{
	char	*tab;
	char	*str;
	int		length;

	tab = "0123456789ABCDEF";
	if (value == -2147483648)
		return (ft_special_itoa(base));
	if (base < 2 || base > 16)
		return (NULL);
	if (!value)
		return (ft_strdup("0"));
	length = ft_intlen_base(value, base);
	if (!(str = (char*)malloc(length + 1)))
		return (NULL);
	if (base == 10 && value < 0)
		str[0] = '-';
	if (value < 0)
		value = -value;
	str[length--] = '\0';
	while (value > 0)
	{
		str[length--] = tab[value % base];
		value = value / base;
	}
	return (str);
}
