/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:24:20 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:09:01 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

/*
**	ft_strncat concatenate n characters of the string s2 after the string s1.
**	WARNING: s1 need sufficient space.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int					i;

	if (n > 0)
	{
		i = ft_strlen(s1);
		while (n-- && *s2)
			s1[i++] = *s2++;
		s1[i] = '\0';
	}
	return (s1);
}
