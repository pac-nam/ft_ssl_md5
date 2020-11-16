/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:36:24 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:21:10 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strpbrk search in the string str the first occurence
**	of a character from charset, and return it address.
**	ft_strpbrk return NULL if no occurence of charset is found.
*/

char	*ft_strpbrk(const char *s, const char *charset)
{
	int		i;
	int		j;

	j = -1;
	while (s[++j])
	{
		i = -1;
		while (charset[++i])
			if (s[j] == charset[i])
				return ((char*)&s[j]);
	}
	return (NULL);
}
