/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:04:59 by tbleuse           #+#    #+#             */
/*   Updated: 2020/02/08 19:49:38 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
**	@param str
**	The ft_str_is_printable() function tests for any character for ft_isprint is
**	true.
************************* RETURN VALUES **********************************
**	The ft_str_is_printable() function returns zero if one of character tests
**	false and returns non-zero if one of character tests true.
*/

int		ft_str_is_printable(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
