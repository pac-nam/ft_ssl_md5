/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <tbleuse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:03:08 by tbleuse           #+#    #+#             */
/*   Updated: 2020/02/08 19:49:38 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"
#include "str.h"
#include "memory.h"
#include <stdlib.h>

/*
**	@param const char **s
**	The ft_tabdub() function allocates sufficient memory for a copy of the
**	tab s1, does the copy, and returns a pointer to it.
**	The pointer may subsequently be used as an argument to the function free.
*/

char			**ft_tabdup(char **s1)
{
	size_t		len;
	size_t		i;
	char		**str;

	len = ft_tablen(s1);
	i = 0;
	if (!(str = ft_tabnew(len)))
		return (NULL);
	while (i < len)
	{
		if (!(str[i] = ft_strdup(s1[i])))
			return (NULL);
		i++;
	}
	str[i] = 0;
	return (str);
}
