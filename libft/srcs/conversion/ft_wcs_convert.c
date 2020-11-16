/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:40:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:02:02 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
#include "memory.h"

/*
**	ft_wcs_convert take the destination, the unicode string and the length
**	of the unicode string. and copy the unicode in the destination string.
**	The size of the string is returned. or 0 if an error occur.
**	The destination have to be allocated with sufficient size.
*/

int			ft_wcs_convert(char *s, wchar_t *pwcs, int n)
{
	char	tmp[sizeof(wchar_t)];
	int		offset;
	int		i;

	offset = 0;
	if (!pwcs)
		return (0);
	while (*pwcs != L'\0' && n != 0)
	{
		if ((i = ft_wc_convert(tmp, *pwcs)) == -1)
			return (-1);
		if (i > n)
			break ;
		ft_memcpy(s + offset, tmp, i);
		offset += i;
		++pwcs;
		n -= i;
	}
	if (n > 0)
		s[offset] = '\0';
	return (offset);
}
