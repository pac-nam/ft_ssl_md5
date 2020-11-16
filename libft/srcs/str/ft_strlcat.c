/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:13:30 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:19:55 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "str.h"

/*
**	ft_strlcat concatenate src after dst. with a maximum length of size.
**	dst will alway finish with a '\0'.
**	ft_strlcat is not clear. Prefer use something else.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size <= i)
		return (size + j);
	if (j < size - i)
	{
		ft_memcpy(dst + i, src, j);
		dst = dst + i + j;
	}
	else
	{
		ft_memcpy(dst + i, src, size - i - 1);
		dst = dst + size - 1;
	}
	*dst = '\0';
	return (i + j);
}
