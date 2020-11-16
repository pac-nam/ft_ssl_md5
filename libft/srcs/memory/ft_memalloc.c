/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:27:23 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:28:44 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory.h"

/*
**	ft_memalloc return pointer with allocation of the size passed in parameter
**	and initialise it to 0.
**	WARNING: ft_memalloc use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

void		*ft_memalloc(size_t size)
{
	void	*locate;

	if (!(locate = (void*)malloc((sizeof(void)) * (size))))
		return (NULL);
	ft_bzero(locate, size);
	return (locate);
}
