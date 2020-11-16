/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:04:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:59:10 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"
#include "conversion.h"

/*
**	ft_ulltoa_base return a string containing the value passed in parameter
**	in the base also passed in parametre.
**	If value base is less 2 or more than 16, 0 is returned too.
**	WARNING: ft_itoa use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	int						i;
	unsigned long long		n2;
	char					*str;

	i = 0;
	n2 = n;
	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	while (n2 > 0)
	{
		n2 = n2 / base;
		i++;
	}
	if (!(str = (char*)malloc(i + 1)))
		return (NULL);
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = HEXA[(n % base)];
		n = n / base;
	}
	return (str);
}
