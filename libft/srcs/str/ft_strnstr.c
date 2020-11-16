/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:56:44 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:17:17 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strnstr return a pointer of the first occurence of the string needle
**	in the first len characters of haystack is returned or NULL if needle is
**	not found.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			save;

	i = 0;
	save = 0;
	if (!needle[0] && len > 0)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = -1;
		while (haystack[i] == needle[++j] && i < len)
		{
			if (!needle[j + 1])
				return ((char*)&haystack[save]);
			++i;
		}
		i = ++save;
	}
	return (NULL);
}
