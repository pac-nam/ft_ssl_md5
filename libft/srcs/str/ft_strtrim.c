/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:07:01 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 14:52:46 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

/*
**	ft_strtrim return a copy of the string passed in parameter
**	without the side spaces.
**	WARNING: ft_strtrim use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] != '\0'
	&& (s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
		++start;
	end = ft_strlen(s) - 1;
	while (end && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		--end;
	if (start >= end)
		return (ft_strdup(""));
	if (!(str = (char*)malloc((end - start) + 1)))
		return (NULL);
	str[end - start] = '\0';
	ft_strncpy(str, &s[start], end - start);
	return (str);
}
