/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:35:32 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:47:24 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strstr return a pointer of the first occurence of the string needle in
**	the haystack is returned or NULL if needle is not found.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int				i;
	int				j;
	int				save;

	if (!needle[0])
		return ((char*)haystack);
	i = 0;
	save = -1;
	while (haystack[i])
	{
		j = -1;
		i = ++save - 1;
		while (haystack[++i] == needle[++j])
			if (!needle[j + 1])
				return ((char*)&haystack[save]);
	}
	return (NULL);
}
