/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:11:54 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:38:57 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strdel free the pointer and set it to 0 if it is pointing on NULL.
*/

void	ft_strdel(char **as)
{
	if (as)
		free(*as);
	*as = NULL;
}
