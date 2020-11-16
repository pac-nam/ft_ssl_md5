/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenwcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:40:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:20:43 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

/*
**	ft_strlenwcs return the length of the unicode string passed in parameter.
*/

size_t		ft_strlenwcs(wchar_t *wcs)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!wcs)
		return (6);
	while (wcs[i] != L'\0')
	{
		if ((wcs[i] >> 7) == 0)
			len += 1;
		else if ((wcs[i] >> 11) == 0)
			len += 2;
		else if ((wcs[i] >> 16) == 0)
			len += 3;
		else if ((wcs[i] >> 21) == 0)
			len += 4;
		i++;
	}
	return (len);
}
