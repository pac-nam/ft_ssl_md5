/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_no_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:04:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:56:22 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "conversion.h"

/*
**	ft_itoa_no_malloc convert the value passed in parameter to string in base
**	10 and put it in the dst passed in parameter.
**	WARNING: dst need sufficient space.
*/

char		*ft_itoa_no_malloc(int n, char *dst)
{
	int		i;

	i = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strcpy(dst, "-2147483648"));
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		n = -n;
	}
	dst[i--] = '\0';
	while (n)
	{
		dst[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (dst);
}
