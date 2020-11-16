/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:59:30 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:42:13 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

/*
**	ft_strsplit split the string passed in parameter by the character c and
**	return a string array of it.
**	WARNING: ft_strsplit use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != c && s[i] && ++count)
			while (s[i] != c && s[i])
				i++;
	return (count);
}

static char	*ft_new_word(char const *str, char c)
{
	int		i;
	char	*dest;

	i = ft_strlen_c(str, c) + 1;
	if (!(dest = (char*)malloc(sizeof(char) * i--)))
		return (NULL);
	dest[i] = '\0';
	while (--i > -1)
		dest[i] = str[i];
	return (dest);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**big_tab;
	int		i;
	int		j;
	int		words;

	if (!s || !c)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(big_tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		if (s[j] != c)
			big_tab[i++] = ft_new_word(&s[j], c);
		while (s[j] != c && s[j])
			j++;
		while (s[j] == c)
			j++;
	}
	big_tab[i] = NULL;
	return (big_tab);
}
