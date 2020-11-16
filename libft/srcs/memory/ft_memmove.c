/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:53:09 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:42:29 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_memmove copy n bytes from src to dst.
**	ft_memmovec can not overlap.
**	WARNING: Destination need sufficient space.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;

	src2 = (char*)src;
	dst2 = (char*)dst;
	if (dst == src || len == 0)
		return (dst);
	if (dst2 < src2)
		while (len--)
			*dst2++ = *src2++;
	else
	{
		dst2 = dst2 + len;
		src2 = src2 + len;
		while (len--)
		{
			dst2--;
			src2--;
			*dst2 = *src2;
		}
	}
	return (dst);
}
