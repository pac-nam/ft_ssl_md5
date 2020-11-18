/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

static void		init_sha512_struct(t_sha512 *ctx)
{
	ft_bzero(ctx, sizeof(t_sha512));
	ctx->h[0] = 0x6a09e667f3bcc908;
	ctx->h[1] = 0xbb67ae8584caa73b;
	ctx->h[2] = 0x3c6ef372fe94f82b;
	ctx->h[3] = 0xa54ff53a5f1d36f1;
	ctx->h[4] = 0x510e527fade682d1;
	ctx->h[5] = 0x9b05688c2b3e6c1f;
	ctx->h[6] = 0x1f83d9abfb41bd6b;
	ctx->h[7] = 0x5be0cd19137e2179;
}

static char		*sha512_last_block(t_sha512 *ctx, const char *m,
		uint64_t length, char *result)
{
	char		buff[128];
	uint64_t	bit_len;

	ft_memcpy(buff, m, length);
	buff[length++] = 0x80;
	if (length > 128 - 16)
	{
		ft_bzero(&(buff[length]), 128 - length);
		sha512_block(ctx, buff);
		length = 0;
	}
	ft_bzero(&(buff[length]), 128 - length);
	bit_len = ctx->l * 8;
	buff[120] = bit_len >> 0x38 & 0xff;
	buff[121] = bit_len >> 0x30 & 0xff;
	buff[122] = bit_len >> 0x28 & 0xff;
	buff[123] = bit_len >> 0x20 & 0xff;
	buff[124] = bit_len >> 0x18 & 0xff;
	buff[125] = bit_len >> 0x10 & 0xff;
	buff[126] = bit_len >> 0x08 & 0xff;
	buff[127] = bit_len >> 0x00 & 0xff;
	sha512_block(ctx, buff);
	return (sha512_h_to_string(ctx, result));
}

char			*sha512_size(const char *m, size_t length)
{
	t_sha512	ctx;
	char		*result;

	if (!(result = (char*)malloc(129)))
		return (NULL);
	init_sha512_struct(&ctx);
	ctx.l = length;
	while (ctx.tmpl + 128 <= ctx.l)
	{
		sha512_block(&ctx, &(m[ctx.tmpl]));
		ctx.tmpl += 128;
	}
	return (sha512_last_block(&ctx, &(m[ctx.tmpl]), ctx.l - ctx.tmpl, result));
}

char			*sha512(const char *m)
{
	t_sha512	ctx;
	char		*result;

	if (!(result = (char*)malloc(129)))
		return (NULL);
	init_sha512_struct(&ctx);
	ctx.l = ft_strlen(m);
	while (ctx.tmpl + 128 <= ctx.l)
	{
		sha512_block(&ctx, &(m[ctx.tmpl]));
		ctx.tmpl += 128;
	}
	return (sha512_last_block(&ctx, &(m[ctx.tmpl]), ctx.l - ctx.tmpl, result));
}

char			*sha512_fd(const int fd)
{
	t_sha512	ctx;
	char		*result;
	int			ret;
	char		buf[128];

	if (!(result = (char*)malloc(129)))
		return (NULL);
	init_sha512_struct(&ctx);
	ctx.l = 0;
	while ((ret = read(fd, buf, 128)) == 128)
	{
		sha512_block(&ctx, buf);
		ctx.l += 128;
	}
	if (ret == -1)
		return (NULL);
	ctx.l += ret;
	return (sha512_last_block(&ctx, buf, ret, result));
}
