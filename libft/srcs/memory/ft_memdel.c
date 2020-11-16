/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:37:59 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:41:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_memdel free the pointer and set it to 0 if it is pointing on NULL.
*/

void	ft_memdel(void **ap)
{
	if (ap)
		free(*ap);
	*ap = NULL;
}
