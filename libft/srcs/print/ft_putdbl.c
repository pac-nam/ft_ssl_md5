/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:01 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:10:48 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "str.h"
#include "conversion.h"

/*
**	print the double nb on the standard output.
**  the double always have deciamal part.
*/

void		ft_putdbl(double n)
{
	char	to_print[64];
	char	*decimal;
	int		i;

	ft_itoa_no_malloc(n, to_print);
	decimal = to_print + ft_strlen(to_print);
	decimal[0] = '.';
	decimal[13] = '\0';
	i = 0;
	while (++i < 13)
	{
		n = (n - (long)n) * 10;
		decimal[i] = ((int)n % 10) + '0';
	}
	--i;
	while (i > 1 && decimal[i] == '0')
		--i;
	decimal[i + 1] = '\0';
	write(1, to_print, ft_strlen(to_print));
}
