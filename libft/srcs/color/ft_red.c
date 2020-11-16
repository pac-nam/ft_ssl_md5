/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "colors.h"
#include "str.h"

/*
**	ft_red will write the string passed in red in the standar output.
**	3 syscall have been used to avoid the use of malloc, but it is not
**	optimized.
*/

void	ft_red(char const *s)
{
	if (s)
	{
		write(1, RED, ft_strlen(RED));
		write(1, s, ft_strlen(s));
		write(1, RESET, ft_strlen(RESET));
	}
}
