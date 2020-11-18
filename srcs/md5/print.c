/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	revers_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
			((n & 0xff00) << 8) | (n << 24));
}

void		print(t_ssl *ssl, t_md5 *md5)
{
	char	*end;

	if (!md5->file_hash)
		end = md5->msg_hash;
	else
		end = md5->file_hash;
	if (!(ssl->args & FLAG_q))
	{
		if (!(ssl->args & FLAG_r) && md5->file_hash)
			ft_printf("MD5 (%s) = ", md5->file_hash);
		if (!(ssl->args & FLAG_r) && !ssl->line
		&& md5->msg_hash && ssl->args & FLAG_s && !md5->file_hash)
			ft_printf("MD5 (\"%s\") = ", md5->msg_hash);
	}
	ft_printf("%s", md5->hash);
	ft_strdel(&md5->hash);
	if ((ssl->args & FLAG_r) && !(ssl->args & FLAG_q))
		ft_printf(" %s\n", end);
	else
		ft_putchar('\n');
	md5->msg_hash = NULL;
	md5->file_hash = NULL;
}
