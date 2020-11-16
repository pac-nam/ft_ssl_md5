/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:37:47 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:43:16 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_memrev reverse n bytes from the pointer.
*/

void		*ft_memrev(void *ptr, size_t size)
{
	size_t		i;
	char		*tmp;
	char		c;

	tmp = ptr;
	i = -1;
	while (++i < --size)
	{
		c = tmp[size];
		tmp[size] = tmp[i];
		tmp[i] = c;
	}
	return (ptr);
}
