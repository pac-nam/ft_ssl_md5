/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:01:45 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:14:08 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversion.h"

/*
**	print length bytes from the pointer in hexadecimal separated by spaces.
*/

void		ft_printmemory(void *ptr, int length)
{
	unsigned char	*str;
	char			to_print[length * 3];
	int				i;

	str = (unsigned char*)ptr;
	i = -1;
	while (++i < length)
	{
		to_print[i * 3] = HEXA[str[i] >> 4];
		to_print[i * 3 + 1] = HEXA[str[i] & 0x0F];
		to_print[i * 3 + 2] = ' ';
	}
	write(1, to_print, i * 3 - 1);
}
