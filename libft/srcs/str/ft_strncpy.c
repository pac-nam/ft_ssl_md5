/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:11:15 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:11:09 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strncpy copy the len first characters from src to dest.
**	WARNING: src and dst can overlap.
**	WARNING: destination need sufficient space.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		x;

	x = 0;
	while (src[x] && x < len)
	{
		dst[x] = src[x];
		x++;
	}
	while (x < len)
		dst[x++] = '\0';
	return (dst);
}
