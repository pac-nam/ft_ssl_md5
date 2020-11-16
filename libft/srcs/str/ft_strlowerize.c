/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowerize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:47:32 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:20:13 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
**	ft_strlowerize lowerize the string passed in parameter and return it.
*/

char		*ft_strlowerize(char *str)
{
	int		x;

	x = -1;
	while (str[++x])
		str[x] = ft_tolower(str[x]);
	return (str);
}
