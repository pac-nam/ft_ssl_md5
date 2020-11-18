/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

const uint32_t		g_sha256_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

/*
** r = rotr
** c = ch
** m = maj
** E = sigma_maj_1
** e = sigma_maj_0
** S = sigma_min_1
** s = sigma_min_0
*/

static t_word		fun(t_word x, t_word y, t_word z, char id)
{
	if (id == 'r')
		return ((x >> y) | (x << (32 - y)));
	if (id == 'c')
		return ((x & y) ^ (~x & z));
	if (id == 'm')
		return ((x & y) ^ (x & z) ^ (y & z));
	if (id == 'E')
		return (fun(x, 6, 0, 'r') ^ fun(x, 11, 0, 'r') ^ fun(x, 25, 0, 'r'));
	if (id == 'e')
		return (fun(x, 2, 0, 'r') ^ fun(x, 13, 0, 'r') ^ fun(x, 22, 0, 'r'));
	if (id == 'S')
		return (fun(x, 17, 0, 'r') ^ fun(x, 19, 0, 'r') ^ (x >> 10));
	if (id == 's')
		return (fun(x, 7, 0, 'r') ^ fun(x, 18, 0, 'r') ^ (x >> 3));
	return (0);
}

static void			fullfil_w(t_word w[64], const char m[64])
{
	int				i;

	i = -1;
	while (++i < 16)
	{
		w[i] = ((m[i * 4 + 0] << 24) & 0xff000000)
				| ((m[i * 4 + 1] << 16) & 0x00ff0000)
				| ((m[i * 4 + 2] << 8) & 0x0000ff00)
				| (m[i * 4 + 3] & 0x000000ff);
	}
	i = 15;
	while (++i < 64)
	{
		w[i] = fun(w[i - 2], 0, 0, 'S') + w[i - 7]
				+ fun(w[i - 15], 0, 0, 's') + w[i - 16];
	}
}

static void			compute_h_copy(t_word h[8], t_word w[64])
{
	int				i;
	t_word			t1;
	t_word			t2;

	i = -1;
	while (++i < 64)
	{
		t1 = h[7] + fun(h[4], 0, 0, 'E') + fun(h[4], h[5], h[6], 'c')
				+ g_sha256_k[i] + w[i];
		t2 = fun(h[0], 0, 0, 'e') + fun(h[0], h[1], h[2], 'm');
		h[7] = h[6];
		h[6] = h[5];
		h[5] = h[4];
		h[4] = h[3] + t1;
		h[3] = h[2];
		h[2] = h[1];
		h[1] = h[0];
		h[0] = t1 + t2;
	}
}

void				sha256_block(t_sha256 *ctx, const char m[64])
{
	t_word			w[64];
	t_word			h_copy[8];

	fullfil_w(w, m);
	ft_memcpy(h_copy, ctx->h, sizeof(uint32_t) * 8);
	compute_h_copy(h_copy, w);
	ctx->h[0] += h_copy[0];
	ctx->h[1] += h_copy[1];
	ctx->h[2] += h_copy[2];
	ctx->h[3] += h_copy[3];
	ctx->h[4] += h_copy[4];
	ctx->h[5] += h_copy[5];
	ctx->h[6] += h_copy[6];
	ctx->h[7] += h_copy[7];
}
