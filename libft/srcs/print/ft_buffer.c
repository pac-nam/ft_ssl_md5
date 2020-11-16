/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 09:20:04 by tbleuse           #+#    #+#             */
/*   Updated: 2019/09/27 09:20:08 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "str.h"

int				ft_end_buff(char *buf, size_t last)
{
	write(1, buf, last);
	return (0);
}

int				ft_add_buff(char *buf, const char *src,
				size_t buffsize, size_t start)
{
	size_t		src_len;

	src_len = ft_strlen(src);
	if (start + src_len < buffsize)
	{
		ft_strcpy(buf + start, src);
		return (start + src_len);
	}
	else
	{
		ft_strncpy(buf + start, src, buffsize - start);
		write(1, buf, buffsize);
		return (ft_add_buff(buf, src + buffsize - start, buffsize, 0));
	}
}
