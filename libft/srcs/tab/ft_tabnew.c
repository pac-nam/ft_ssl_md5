/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:03:16 by tbleuse           #+#    #+#             */
/*   Updated: 2020/02/08 19:49:38 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include <stdlib.h>

/*
**	@param const size_t size
**	The ft_tabnew() allocate a new tab of size `size`
************************* RETURN VALUES **********************************
**	The ft_tabnew() function returns the new tab set to zero or NULL
**	if allocate fail.
*/

char		**ft_tabnew(size_t size)
{
	char	**str;

	if (!(str = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	return (str);
}
