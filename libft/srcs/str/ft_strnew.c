/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:49:16 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:14:38 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strnew return pointer with allocation of the size passed in parameter
**	and initialise it to 0.
**	WARNING: ft_strnew use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(++size)))
		return (NULL);
	while (size > 0)
		str[--size] = '\0';
	return (str);
}
