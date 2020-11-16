/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:32:33 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:40:42 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_memcpy copy the n bytes from src to dst.
**	If src and dst are close, use ft_memmove to avoid overlap.
**	WARNING: Destination need sufficient space.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;
	const char	*tmp2;

	i = -1;
	tmp = dst;
	tmp2 = src;
	while (++i < n)
		tmp[i] = tmp2[i];
	return (dst);
}
