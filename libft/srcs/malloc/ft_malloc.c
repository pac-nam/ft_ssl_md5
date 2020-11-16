/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/09/12 16:20:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"
#include "malloc_srcs.h"
#include "math.h"

void			*ft_find_cluster(t_block *page, int size)
{
	t_cluster	*cluster;

	size = ft_malloc_good_size(size) + CLUSTERSIZE;
	while (page)
	{
		cluster = ((void*)page) + BLOCKSIZE;
		while ((void*)cluster < (void*)page + page->size - size)
		{
			if (cluster->freesize > size)
			{
				((t_cluster*)((void*)cluster + size))->freesize =
				cluster->freesize - size;
				cluster->freesize = -size;
				return ((void*)cluster + CLUSTERSIZE);
			}
			cluster = (t_cluster*)((void*)cluster + ft_abs(cluster->freesize));
		}
		page = page->next;
	}
	return (NULL);
}

void			*ft_new_page(t_block **block, size_t size)
{
	size_t		alloc_length;
	t_block		*new_block;
	t_cluster	*new_cluster;

	alloc_length = PAGESIZE;
	while ((size <= TINY && alloc_length < (TINY + CS) * 100 + BLOCKSIZE)
	|| (size <= SMALL && alloc_length < (SMALL + CS) * 100 + BLOCKSIZE))
		alloc_length += PAGESIZE;
	if (SMALL < size)
		alloc_length = size + CLUSTERSIZE + BLOCKSIZE;
	if ((new_block = mmap(0, alloc_length, PROT_READ | PROT_WRITE,
	MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
		return (NULL);
	new_block->size = alloc_length;
	new_block->next = *block;
	*block = new_block;
	new_cluster = (void*)new_block + BLOCKSIZE;
	if (size <= SMALL)
		new_cluster->freesize = alloc_length - BLOCKSIZE;
	else
		new_cluster->freesize = LARGE;
	return (((void*)new_cluster) + CLUSTERSIZE);
}

void			*ft_malloc(size_t size)
{
	void		*result;

	if (size <= TINY)
	{
		if (!(result = ft_find_cluster(g_alloc.tiny, size)))
			if (ft_new_page(&g_alloc.tiny, TINY))
				result = ft_find_cluster(g_alloc.tiny, size);
	}
	else if (size <= SMALL)
	{
		if (!(result = ft_find_cluster(g_alloc.small, size)))
			if (ft_new_page(&g_alloc.small, SMALL))
				result = ft_find_cluster(g_alloc.small, size);
	}
	else
		result = ft_new_page(&g_alloc.large, size);
	return (result);
}
