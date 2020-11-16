/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:40:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:00:44 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

/*
**	ft_wc_convert take the destination, the unicode charactere and put the
**	charactere in the string.
**	The size of the charactere is returned. or -1 if an error occur
**	The destination have to be allocated with sufficient size.
*/

int			ft_wc_convert(char *s, wchar_t wchar)
{
	if ((wchar < 0) || (wchar >= 0xD800 && wchar <= 0xDFFF) ||
			(wchar > 0x10FFFF))
		return (-1);
	if ((wchar >> 7) == 0)
	{
		s[0] = (unsigned char)wchar;
		return (1);
	}
	if ((wchar >> 11) == 0)
		return (ft_conv_utf8(2, wchar, s));
	if ((wchar >> 16) == 0)
		return (ft_conv_utf8(3, wchar, s));
	if ((wchar >> 21) == 0)
		return (ft_conv_utf8(4, wchar, s));
	return (-1);
}
