/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
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

int				ft_check_ptr(t_block *page, void *to_find)
{
	t_cluster	*cluster;

	if (!page || !to_find)
		return (0);
	cluster = (t_cluster*)((void*)page + BLOCKSIZE);
	while ((void*)cluster + CLUSTERSIZE < to_find)
		cluster = (t_cluster*)((void*)cluster + ft_abs(cluster->freesize));
	if ((void*)cluster + CLUSTERSIZE == to_find)
		return (1);
	return (0);
}

t_block			*ft_get_malloc_page(void *ptr)
{
	t_block		*tmp;

	if (!ptr)
		return (NULL);
	tmp = g_alloc.tiny;
	while (tmp)
		if ((void*)tmp < ptr && ptr < (void*)tmp + tmp->size
		&& ft_check_ptr(tmp, ptr))
			return (tmp);
		else
			tmp = tmp->next;
	tmp = g_alloc.small;
	while (tmp)
		if ((void*)tmp < ptr && ptr < (void*)tmp + tmp->size
		&& ft_check_ptr(tmp, ptr))
			return (tmp);
		else
			tmp = tmp->next;
	tmp = g_alloc.large;
	while (tmp)
		if ((void*)tmp + BLOCKSIZE + CLUSTERSIZE == ptr)
			return (tmp);
		else
			tmp = tmp->next;
	return (NULL);
}

void			ft_free_page(t_block **start, t_block *to_free)
{
	t_block		*tmp;

	if (to_free == *start)
	{
		*start = to_free->next;
		munmap(to_free, to_free->size);
		return ;
	}
	tmp = *start;
	while (tmp->next)
	{
		if (tmp->next == to_free)
		{
			tmp->next = tmp->next->next;
			munmap(to_free, to_free->size);
			return ;
		}
		tmp = tmp->next;
	}
}

void			free_cluster(t_block **start, t_block *page, void *to_free)
{
	t_cluster	*c[3];

	c[0] = (void*)page + BLOCKSIZE;
	c[1] = (t_cluster*)(((void*)c[0]) + ft_abs(c[0]->freesize));
	if ((void*)c[0] == to_free)
	{
		c[0]->freesize = -c[0]->freesize;
		c[0]->freesize += (c[1]->freesize > 0) ? c[1]->freesize : 0;
	}
	else
		while ((void*)c[1] < (void*)page + page->size)
		{
			if ((void*)c[1] == to_free)
			{
				c[1]->freesize = ft_abs(c[1]->freesize);
				c[2] = (t_cluster*)(((void*)c[1]) + c[1]->freesize);
				c[1]->freesize += (c[2]->freesize > 0) ? c[2]->freesize : 0;
				c[0]->freesize += (c[0]->freesize > 0) ? c[1]->freesize : 0;
			}
			c[0] = c[1];
			c[1] = (t_cluster*)(((void*)c[1]) + ft_abs(c[1]->freesize));
		}
	if (((t_cluster*)((void*)page + BLOCKSIZE))->freesize ==
	(int)(page->size - BLOCKSIZE))
		ft_free_page(start, page);
}

void			ft_free(void *ptr)
{
	t_block		*page;
	t_cluster	*cluster;

	if ((page = ft_get_malloc_page(ptr)))
	{
		cluster = ptr - CLUSTERSIZE;
		if (cluster->freesize > 0)
			return ;
		else if (cluster->freesize == LARGE)
			ft_free_page(&g_alloc.large, page);
		else if (-cluster->freesize - CLUSTERSIZE <= TINY)
			free_cluster(&g_alloc.tiny, page, cluster);
		else if (-cluster->freesize - CLUSTERSIZE <= SMALL)
			free_cluster(&g_alloc.small, page, cluster);
	}
}
