/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:45:45 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:00:51 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

/*
**	ft_strmapi apply the function passed in parameter on each character of a
**	copy of the string s. The index of the character is also passed to the
**	function.The copy is returned.
**	WARNING: ft_strmapi use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*dest;
	unsigned int		i;

	if (!s || !(dest = ft_strdup(s)))
		return (NULL);
	i = -1;
	while (s[++i])
		dest[i] = f(i, s[i]);
	dest[i] = '\0';
	return (dest);
}
