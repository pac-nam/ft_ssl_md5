/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:41:46 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:43:55 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_bzero write len c from the pointer.
*/

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;
	size_t			i;

	b2 = b;
	i = -1;
	while (++i < len)
		b2[i] = (unsigned char)c;
	return (b);
}
