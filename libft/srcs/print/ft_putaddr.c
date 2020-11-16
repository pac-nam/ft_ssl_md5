/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:44:15 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:16:48 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	print address of the pointer passed in parameter.
*/

void					ft_putaddr(void *ptr)
{
	unsigned long long	cpy;
	int					index;
	char				str[16];

	cpy = (unsigned long)ptr;
	str[0] = '0';
	str[1] = 'x';
	index = 14;
	while (--index > 1)
	{
		str[index] = (cpy % 16) + '0';
		if (str[index] > '9')
			str[index] += 7;
		cpy = cpy / 16;
	}
	write(1, str, 14);
}
