/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:11:15 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:38:15 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strcpy copy all characters from src to dest.
**	WARNING: src and dst can overlap.
**	WARNING: destination need sufficient space.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = -1;
	if (!src || !dst)
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
