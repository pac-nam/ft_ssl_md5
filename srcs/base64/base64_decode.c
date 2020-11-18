/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base64.h"

static const unsigned char g_d[] = {
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 64, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 62, 66, 66, 66, 63, 52, 53, 54, 55, 56, 57,
	58, 59, 60, 61, 66, 66, 66, 65, 66, 66, 66, 0, 1, 2, 3, 4, 5, 6,
	7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	25, 66, 66, 66, 66, 66, 66, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
	37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66,
	66, 66, 66, 66
};

static uint8_t		*ft_clean_str(char *str, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (ft_isspace(str[i]))
		{
			i++;
			continue ;
		}
		str[j] = str[i];
		i++;
		j++;
	}
	if (i != j)
		str[j] = '\0';
	return ((uint8_t *)str);
}

static bool			init_base64_decode(t_base64_decode *base, uint8_t *str,
	char *hex)
{
	base->msg = ft_clean_str((char *)str, ft_strlen((char *)str));
	base->msg_size = ft_strlen((char *)base->msg);
	base->hex = hex;
	base->str_decode_size = ((base->msg_size / 4 * 3) -
		(ft_strstr((char *)base->msg, "==") ? 1 : 0));
	if (!(base->str_decode = ft_strnew(base->str_decode_size)))
		return (false);
	base->end = base->msg + base->msg_size;
	base->buff = 0;
	base->index = 0;
	base->iter = 0;
	return (true);
}

static char			*finish_base64_decode(t_base64_decode *base64)
{
	char			*ret;

	if (base64->iter == 3)
	{
		base64->str_decode[base64->index++] = (base64->buff >> 10) & 255;
		if (base64->index > base64->str_decode_size)
			return (NULL);
		base64->str_decode[base64->index++] = (base64->buff >> 2) & 255;
		if (base64->index > base64->str_decode_size)
			return (NULL);
	}
	if (base64->iter == 2)
		base64->str_decode[base64->index++] = (base64->buff >> 4) & 255;
	if (base64->index > base64->str_decode_size
	|| !(ret = ft_strdup(base64->str_decode)))
	{
		ft_strdel(&base64->str_decode);
		return (NULL);
	}
	ft_strdel(&base64->str_decode);
	if (ft_str_is_printable(ret))
		return (ret);
	ft_strdel(&ret);
	return (NULL);
}

static bool			process_base64_decode(t_base64_decode *base64, size_t *i)
{
	base64->buff = base64->buff << 6 | base64->c;
	(*i)++;
	base64->iter++;
	if (base64->iter == 4)
	{
		base64->str_decode[base64->index++] = (base64->buff >> 16) & 255;
		if (base64->index > base64->str_decode_size)
			return (false);
		base64->str_decode[base64->index++] = (base64->buff >> 8) & 255;
		if (base64->index > base64->str_decode_size)
			return (false);
		base64->str_decode[base64->index++] = base64->buff & 255;
		if (base64->index > base64->str_decode_size)
			return (false);
		base64->buff = 0;
		base64->iter = 0;
	}
	return (true);
}

char				*base64_decode(char *str, char *hex)
{
	t_base64_decode	base64;
	size_t			i;

	i = 0;
	if (!(init_base64_decode(&base64, (uint8_t *)str, hex)))
		return (NULL);
	while (i < base64.msg_size)
	{
		base64.c = g_d[base64.msg[i]];
		if (base64.c == 64)
		{
			i++;
			continue ;
		}
		else if (base64.c == 65)
			break ;
		else if (base64.c == 66)
			return (NULL);
		else if (!(process_base64_decode(&base64, &i)))
			return (NULL);
	}
	return (finish_base64_decode(&base64));
}
