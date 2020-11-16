/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "malloc_srcs.h"
#include "math.h"
#include "memory.h"

void			*ft_ugly_realloc(void *ptr, size_t size)
{
	t_cluster	*cluster;
	void		*new_ptr;
	size_t		largesize;

	if (!ft_check_ptr(ft_get_malloc_page(ptr), ptr))
		return (NULL);
	cluster = (void*)ptr - CLUSTERSIZE;
	if (!(new_ptr = ft_malloc(size)))
		return (NULL);
	if (cluster->freesize == LARGE)
	{
		largesize = ((t_block*)((void*)cluster - BLOCKSIZE))->size
		- BLOCKSIZE - CLUSTERSIZE;
		ft_memcpy(new_ptr, ptr, (largesize < size) ? largesize : size);
	}
	else
		ft_memcpy(new_ptr, ptr,
		(ft_abs(cluster->freesize) - CLUSTERSIZE < size)
		? ft_abs(cluster->freesize) - CLUSTERSIZE : size);
	ft_free(ptr);
	return (new_ptr);
}

void			*realloc_size(t_block *page, t_cluster *to_realloc, int size)
{
	t_cluster	*c[3];

	if (-to_realloc->freesize == size)
		return ((void*)to_realloc + CLUSTERSIZE);
	c[0] = (t_cluster*)((void*)page + BLOCKSIZE);
	while (c[0] < to_realloc)
		c[0] = (void*)c[0] + ft_abs(c[0]->freesize);
	if (c[0] != to_realloc)
		return (NULL);
	c[1] = (t_cluster*)((void*)c[0] + ft_abs(c[0]->freesize));
	c[2] = (t_cluster*)((void*)c[0] + size);
	if (size < -c[0]->freesize)
	{
		c[2]->freesize = (-c[0]->freesize) - size;
		c[0]->freesize = -size;
	}
	else if ((int)((-c[0]->freesize) + c[1]->freesize) > size)
	{
		if ((int)((-c[0]->freesize) + c[1]->freesize) != size)
			c[2]->freesize = ((-c[0]->freesize) + c[1]->freesize) - size;
		c[0]->freesize = -size;
	}
	else
		return (ft_ugly_realloc(((void*)to_realloc) + CS, size - CS));
	return ((void*)c[0] + CLUSTERSIZE);
}

void			*ft_realloc(void *ptr, size_t size)
{
	t_cluster	*cluster;
	int			freesize;
	t_block		*page;

	if (!size)
		ft_free(ptr);
	if (!ptr || (ptr && !size))
		return (ft_malloc(ft_malloc_good_size(size)));
	if (!(page = ft_get_malloc_page(ptr)))
		return (NULL);
	size = ft_malloc_good_size(size);
	cluster = (t_cluster*)(ptr - CLUSTERSIZE);
	freesize = ft_abs(cluster->freesize) - CLUSTERSIZE;
	if (cluster->freesize > 0)
		return (ft_malloc(size));
	else if (cluster->freesize == LARGE && size > SMALL
	&& page->size == size + BLOCKSIZE + CLUSTERSIZE)
		return (ptr);
	else if (TINY < freesize && freesize <= SMALL
	&& TINY < size && size <= SMALL)
		return (realloc_size(page, cluster, size + CLUSTERSIZE));
	else if (freesize <= TINY && size <= TINY)
		return (realloc_size(page, cluster, size + CLUSTERSIZE));
	return (ft_ugly_realloc(ptr, size));
}
