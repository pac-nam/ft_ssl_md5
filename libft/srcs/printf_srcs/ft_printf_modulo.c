/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:26:58 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:07:01 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "memory.h"
#include "print.h"

int	ft_printf_modulo(int **info)
{
	int		count;

	count = 1;
	if ((*info)[2] == -1)
	{
		if ((*info)[1] == -1)
			count += ft_printnchar((*info)[5] - 1, ' ');
		else
			count += ft_printnchar((*info)[5] - 1, '0');
	}
	write(1, "%", 1);
	if ((*info)[2] != -1)
	{
		if ((*info)[1] == -1)
			count += ft_printnchar((*info)[5] - 1, ' ');
		else
			count += ft_printnchar((*info)[5] - 1, '0');
	}
	ft_memdel((void**)info);
	return (count);
}
