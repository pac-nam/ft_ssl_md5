/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_srcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_SRCS_H
# define MALLOC_SRCS_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_cluster
{
	int					freesize;
}						t_cluster;

typedef	struct			s_block
{
	size_t				size;
	struct s_block		*next;
}						t_block;

typedef struct			s_context
{
	t_block				*tiny;
	t_block				*small;
	t_block				*large;
}						t_context;

t_context				g_alloc;

t_block					*ft_get_malloc_page(void *ptr);
int						ft_check_ptr(t_block *page, void *to_find);

# define TINY	1024
# define SMALL	1024*128
# define LARGE	-1
# define ALIGN	16
# define PAGESIZE getpagesize()
# define BLOCKSIZE ft_malloc_good_size(sizeof(t_block))
# define CLUSTERSIZE ft_malloc_good_size(sizeof(t_cluster))
# define CS CLUSTERSIZE

#endif
