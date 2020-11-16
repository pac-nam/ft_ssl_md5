/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base_no_malloc.c                           :+:      :+:    :+:   */
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
#include "math.h"

/*
**	ft_itoa_base return a string containing the value passed in parameter
**	in the base also passed in parametre.
**	If value is less than 0 and base is not 10, 0 is returned.
**	If value base is less 2 or more than 16, 0 is returned too.
**	WARNING: ft_itoa use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char		*ft_utoa_base_no_malloc(uint32_t value, char *dst, int base)
{
	char	*tab;
	int		length;

	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	if (!value)
		return (ft_strcpy(dst, "0"));
	length = 8;
	dst[length--] = '\0';
	while (length >= 0)
	{
		dst[length--] = tab[value % base];
		value = value / base;
	}
	return (dst);
}
