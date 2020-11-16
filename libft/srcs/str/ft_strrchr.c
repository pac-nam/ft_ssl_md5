/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:36:24 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:23:04 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
**	ft_strchr search in the string str the last occurence
**	of the charactere c, and return it address.
**	ft_strchr return NULL if the character c is not found.
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s) + 1;
	while (--i > -1)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (NULL);
}
