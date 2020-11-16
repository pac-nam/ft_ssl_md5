/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:04:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:58:35 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "str.h"
#include "conversion.h"

/*
**	ft_lltoa take return a string containing the value passed in parameter
**	in base 10.
**	WARNING: ft_itoa use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char		*ft_lltoa(long long n)
{
	char	*str;
	int		i;

	i = ft_lllen(n);
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
