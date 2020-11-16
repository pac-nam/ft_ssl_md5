/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>

void					ft_free(void *ptr);
void					*ft_malloc(size_t size);
void					*ft_realloc(void *ptr, size_t size);
void					ft_show_alloc_mem(void);
void					*ft_calloc(size_t nmemb, size_t size);
void					*ft_reallocf(void *ptr, size_t size);
size_t					ft_malloc_good_size(size_t size);
size_t					ft_malloc_size(void *ptr);

#endif
