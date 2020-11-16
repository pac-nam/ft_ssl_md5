/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_good_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/09/12 16:20:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "malloc_srcs.h"
#include "math.h"

size_t			ft_malloc_good_size(size_t x)
{
	if (x == 0)
		return (ALIGN);
	return (((x + ALIGN - 1) / ALIGN) * ALIGN);
}

size_t			ft_malloc_size(void *ptr)
{
	t_block		*page;
	t_cluster	*cluster;

	if ((page = ft_get_malloc_page(ptr)))
	{
		cluster = (t_cluster*)(ptr - CLUSTERSIZE);
		if (cluster->freesize == LARGE)
			return (page->size - BLOCKSIZE - CLUSTERSIZE);
		return ((size_t)(ft_abs(cluster->freesize) - CLUSTERSIZE));
	}
	return (0);
}
