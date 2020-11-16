/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:45:53 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 13:25:00 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
**	ft_lstrev reverse characters in the string passed in parameter.
*/

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = -1;
	j = ft_strlen(str);
	while (++i < --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	return (str);
}
