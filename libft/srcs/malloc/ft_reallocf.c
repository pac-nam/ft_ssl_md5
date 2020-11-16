/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "malloc_srcs.h"

void			*ft_reallocf(void *ptr, size_t size)
{
	t_cluster	*cluster;
	t_block		*block;
	void		*new;

	if (!(new = ft_realloc(ptr, size)))
	{
		ft_free(ptr);
		return (NULL);
	}
	cluster = (t_cluster*)(new - CLUSTERSIZE);
	block = (t_block*)(((void*)cluster) - BLOCKSIZE);
	if ((cluster->freesize == LARGE
	&& block->size - BLOCKSIZE - CLUSTERSIZE != size)
	|| (cluster->freesize != LARGE
	&& (-cluster->freesize) - CLUSTERSIZE != size))
	{
		ft_free(ptr);
		ptr = NULL;
	}
	return (new);
}
