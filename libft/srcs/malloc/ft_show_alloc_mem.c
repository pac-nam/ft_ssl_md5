/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_alloc_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "malloc.h"
#include "malloc_srcs.h"
#include "math.h"
#include "print.h"

int				ft_print_clusters(t_cluster *cluster, void *limit)
{
	int			cpt;

	cpt = 0;
	while ((void*)cluster < (void*)limit)
	{
		ft_putstr("\t\t");
		ft_putaddr((void*)cluster + CLUSTERSIZE);
		ft_putstr(" - ");
		ft_putaddr((void*)cluster + ft_abs(cluster->freesize));
		ft_putstr(" ");
		ft_putnbr(ft_abs(cluster->freesize) - CLUSTERSIZE);
		if (cluster->freesize < 0)
		{
			ft_putstr(" used\n");
			cpt += -cluster->freesize - CLUSTERSIZE;
		}
		else if (cluster->freesize > 0)
			ft_putstr(" free\n");
		cluster = (void*)cluster + ft_abs(cluster->freesize);
	}
	return (cpt);
}

int				ft_print_pages(t_block *page)
{
	int			page_number;
	int			cpt;
	t_block		*tmp_page;

	page_number = 0;
	cpt = 0;
	tmp_page = page;
	while (tmp_page)
	{
		ft_putstr("\n\tPAGE ");
		ft_putnbr(++page_number);
		ft_putstr("  ");
		ft_putaddr(tmp_page);
		ft_putstr(" - ");
		ft_putaddr((void*)tmp_page + tmp_page->size);
		ft_putstr(" ");
		ft_putnbr(tmp_page->size);
		ft_putstr(" octets\n");
		cpt += ft_print_clusters((t_cluster*)((void*)tmp_page + BLOCKSIZE),
		(void*)tmp_page + tmp_page->size);
		tmp_page = tmp_page->next;
	}
	return (cpt);
}

void			ft_show_alloc_mem(void)
{
	t_block		*tmp_page;
	int			cpt;

	cpt = 0;
	ft_magenta("TINY:");
	cpt += ft_print_pages(g_alloc.tiny);
	ft_magenta("\nSMALL:");
	cpt += ft_print_pages(g_alloc.small);
	ft_magenta("\nLARGES:\n");
	tmp_page = g_alloc.large;
	while (tmp_page)
	{
		ft_putstr("\t");
		ft_putaddr((void*)tmp_page + CLUSTERSIZE + BLOCKSIZE);
		ft_putstr(" - ");
		ft_putaddr((void*)tmp_page + tmp_page->size);
		ft_putstr(" ");
		ft_putnbr(tmp_page->size - CLUSTERSIZE - BLOCKSIZE);
		ft_putstr(" octets\n");
		cpt += tmp_page->size - CLUSTERSIZE - BLOCKSIZE;
		tmp_page = tmp_page->next;
	}
	ft_green("Total: ");
	ft_putnbr(cpt);
	ft_putstr(" octets\n");
}
