/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:45:45 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:20:57 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

/*
**	ft_strmap apply the function passed in parameter on
**	each character of a copy of the string s. The copy is returned.
**	WARNING: ft_strmap use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char		*ft_strmap(char const *s, char (*f)(char))
{
	char				*dest;
	unsigned int		i;

	if (!s || !(dest = ft_strdup(s)))
		return (NULL);
	i = -1;
	while (s[++i])
		dest[i] = f(s[i]);
	dest[i] = '\0';
	return (dest);
}
