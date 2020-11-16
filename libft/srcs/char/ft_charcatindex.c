/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcatindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:01:18 by tbleuse           #+#    #+#             */
/*   Updated: 2020/02/08 19:49:38 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
**	Concatenate a char into a buffer in an index and put a \0
**	@param buf
**	@param index to put in buffer
**	@param c the char to concatenate
*/

void		ft_charcatindex(char *buf, size_t *index, const char c)
{
	(buf)[(*index)] = c;
	(*index)++;
	(buf)[(*index)] = '\0';
}
