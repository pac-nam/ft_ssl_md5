#include "sha512.h"

static void		init_sha384_struct(t_sha512 *ctx)
{
	ft_bzero(ctx, sizeof(t_sha512));
	ctx->h[0] = 0xCBBB9D5DC1059ED8;
	ctx->h[1] = 0x629A292A367CD507;
	ctx->h[2] = 0x9159015A3070DD17;
	ctx->h[3] = 0x152FECD8F70E5939;
	ctx->h[4] = 0x67332667FFC00B31;
	ctx->h[5] = 0x8EB44A8768581511;
	ctx->h[6] = 0xDB0C2E0D64F98FA7;
	ctx->h[7] = 0x47B5481DBEFA4FA4;
}

static char		*sha384_last_block(t_sha512 *ctx, const char *m,
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
	result = sha512_h_to_string(ctx, result);
	result[96] = '\0';
	return (result);
}

char			*sha384_size(const char *m, size_t length)
{
	t_sha512	ctx;
	char		*result;

	if (!(result = (char*)malloc(129)))
		return (NULL);
	init_sha384_struct(&ctx);
	ctx.l = length;
	while (ctx.tmpl + 128 <= ctx.l)
	{
		sha512_block(&ctx, &(m[ctx.tmpl]));
		ctx.tmpl += 128;
	}
	return (sha384_last_block(&ctx, &(m[ctx.tmpl]), ctx.l - ctx.tmpl, result));
}

char			*sha384(const char *m)
{
	t_sha512	ctx;
	char		*result;

	if (!(result = (char*)malloc(129)))
		return (NULL);
	init_sha384_struct(&ctx);
	ctx.l = ft_strlen(m);
	while (ctx.tmpl + 128 <= ctx.l)
	{
		sha512_block(&ctx, &(m[ctx.tmpl]));
		ctx.tmpl += 128;
	}
	return (sha384_last_block(&ctx, &(m[ctx.tmpl]), ctx.l - ctx.tmpl, result));
}

char			*sha384_fd(const int fd)
{
	t_sha512	ctx;
	char		*result;
	int			ret;
	char		buf[128];

	if (!(result = (char*)malloc(129)))
		return (NULL);
	init_sha384_struct(&ctx);
	ctx.l = 0;
	while ((ret = read(fd, buf, 128)) == 128)
	{
		sha512_block(&ctx, buf);
		ctx.l += 128;
	}
	if (ret == -1)
		return (NULL);
	ctx.l += ret;
	return (sha384_last_block(&ctx, buf, ret, result));
}