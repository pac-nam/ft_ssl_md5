/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncatindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:09:09 by tbleuse           #+#    #+#             */
/*   Updated: 2020/02/08 19:49:38 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
**	@param buf
**	@param index to put in buffer
**	@param str the string to concatenate
**	@param len length of str
**	The ft_strncatindex functions start to index in paramater and append a copy
**	of the null-terminated string s2 to the end of the null-terminated str s1,
**	then add a terminating `\0'.  The string s1 must have
**		sufficient space to hold the result.
**	The ft_strncatindex function appends not more than n characters from s2,
**		and then adds a terminating `\0'
************************* RETURN VALUES **********************************
**	The ft_strncatindex functions return the pointer s1.
*/

void		ft_strncatindex(char *buf, size_t *index, const char *str,
												const size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(buf)[*index] = str[i];
		i++;
		(*index)++;
	}
	(buf)[(*index)] = '\0';
}
