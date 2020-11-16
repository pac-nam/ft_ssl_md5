/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:04:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 13:56:22 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
#include "str.h"

/*
**	ft_dtoa take return a string containing the value passed in parameter
**	in base 10.
**	WARNING: ft_dtoa use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char			*ft_dtoa(double n)
{
	char	dst[64];
	char	*decimal;
	int		i;

	ft_itoa_no_malloc(n, dst);
	decimal = dst + ft_strlen(dst);
	decimal[0] = '.';
	decimal[13] = '\0';
	i = 0;
	while (++i < 13)
	{
		n = (n - (long)n) * 10;
		decimal[i] = ((int)n % 10) + '0';
	}
	--i;
	while (i > 1 && decimal[i] == '0')
		--i;
	decimal[i + 1] = '\0';
	return (ft_strdup(dst));
}
