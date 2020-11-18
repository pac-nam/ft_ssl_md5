/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64.h"

static bool		init_base64(t_base64 *base64, uint8_t *str, size_t n, char *hex)
{
	base64->hash_size = (((4 * n / 3) + 3) & ~3);
	if (!(base64->hash = ft_strnew(base64->hash_size)))
		return (false);
	base64->msg = str;
	base64->msg_size = n;
	base64->pad_count = n % 3;
	base64->index = 0;
	base64->h = 0;
	base64->hex = hex;
	return (true);
}

static char		*finish_base64(t_base64 *base64)
{
	char		*ret;

	while (base64->pad_count < 3)
	{
		if (base64->pad_count == 0)
			break ;
		base64->hash[base64->index] = '=';
		base64->index++;
		base64->pad_count++;
	}
	if (!(ret = ft_strdup(base64->hash)))
	{
		ft_strdel(&base64->hash);
		return (NULL);
	}
	ft_strdel(&base64->hash);
	return (ret);
}

static void		process_base64(t_base64 *base64, size_t i)
{
	base64->h = ((uint32_t)base64->msg[i]) << 16;
	if ((i + 1) < base64->msg_size)
		base64->h += ((uint32_t)base64->msg[i + 1]) << 8;
	if ((i + 2) < base64->msg_size)
		base64->h += base64->msg[i + 2];
	base64->h0 = (uint8_t)(base64->h >> 18) & 63;
	base64->h1 = (uint8_t)(base64->h >> 12) & 63;
	base64->h2 = (uint8_t)(base64->h >> 6) & 63;
	base64->h3 = (uint8_t)base64->h & 63;
	base64->hash[base64->index++] = base64->hex[base64->h0];
	base64->hash[base64->index++] = base64->hex[base64->h1];
	if ((i + 1) < base64->msg_size)
		base64->hash[base64->index++] = base64->hex[base64->h2];
	if ((i + 2) < base64->msg_size)
		base64->hash[base64->index++] = base64->hex[base64->h3];
}

char			*base64_encode(char *str, size_t size, char *hex)
{
	t_base64	base64;
	size_t		i;

	i = 0;
	if (!(init_base64(&base64, (uint8_t *)str, size, hex)))
		return (NULL);
	while (i < size)
	{
		process_base64(&base64, i);
		i += 3;
	}
	return (finish_base64(&base64));
}
