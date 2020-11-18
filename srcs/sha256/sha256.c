/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

static void		init_sha256_struct(t_sha256 *ctx)
{
	ft_bzero(ctx, sizeof(t_sha256));
	ctx->h[0] = 0x6a09e667;
	ctx->h[1] = 0xbb67ae85;
	ctx->h[2] = 0x3c6ef372;
	ctx->h[3] = 0xa54ff53a;
	ctx->h[4] = 0x510e527f;
	ctx->h[5] = 0x9b05688c;
	ctx->h[6] = 0x1f83d9ab;
	ctx->h[7] = 0x5be0cd19;
}

static char		*sha256_last_block(t_sha256 *ctx, const char *m,
		uint64_t length, char *result)
{
	char		buff[64];
	uint64_t	bit_len;

	ft_memcpy(buff, m, length);
	buff[length++] = 0x80;
	if (length > 64 - sizeof(uint64_t))
	{
		ft_bzero(&(buff[length]), 64 - length);
		sha256_block(ctx, buff);
		length = 0;
	}
	ft_bzero(&(buff[length]), 64 - length);
	bit_len = ctx->l * 8;
	buff[56] = bit_len >> 0x38 & 0xff;
	buff[57] = bit_len >> 0x30 & 0xff;
	buff[58] = bit_len >> 0x28 & 0xff;
	buff[59] = bit_len >> 0x20 & 0xff;
	buff[60] = bit_len >> 0x18 & 0xff;
	buff[61] = bit_len >> 0x10 & 0xff;
	buff[62] = bit_len >> 0x08 & 0xff;
	buff[63] = bit_len >> 0x00 & 0xff;
	sha256_block(ctx, buff);
	return (sha256_h_to_string(ctx, result));
}

char			*sha256_size(const char *m, size_t length)
{
	t_sha256	ctx;
	char		*result;

	if (!(result = (char*)malloc(65)))
		return (NULL);
	init_sha256_struct(&ctx);
	ctx.l = length;
	while (ctx.tmpl + 64 <= ctx.l)
	{
		sha256_block(&ctx, &(m[ctx.tmpl]));
		ctx.tmpl += 64;
	}
	return (sha256_last_block(&ctx, &(m[ctx.tmpl]), ctx.l - ctx.tmpl, result));
}

char			*sha256(const char *m)
{
	t_sha256	ctx;
	char		*result;

	if (!(result = (char*)malloc(65)))
		return (NULL);
	init_sha256_struct(&ctx);
	ctx.l = ft_strlen(m);
	while (ctx.tmpl + 64 <= ctx.l)
	{
		sha256_block(&ctx, &(m[ctx.tmpl]));
		ctx.tmpl += 64;
	}
	return (sha256_last_block(&ctx, &(m[ctx.tmpl]), ctx.l - ctx.tmpl, result));
}

char			*sha256_fd(const int fd)
{
	t_sha256	ctx;
	char		*result;
	int			ret;
	char		buf[64];

	if (!(result = (char*)malloc(65)))
		return (NULL);
	init_sha256_struct(&ctx);
	ctx.l = 0;
	while ((ret = read(fd, buf, 64)) == 64)
	{
		sha256_block(&ctx, buf);
		ctx.l += 64;
	}
	if (ret == -1)
		return (NULL);
	ctx.l += ret;
	return (sha256_last_block(&ctx, buf, ret, result));
}
