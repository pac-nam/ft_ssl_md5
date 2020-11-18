/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

const t_word		g_sha512_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
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
		return ((x >> y) | (x << (64 - y)));
	if (id == 'c')
		return ((x & y) ^ (~x & z));
	if (id == 'm')
		return ((x & y) ^ (x & z) ^ (y & z));
	if (id == 'E')
		return (fun(x, 14, 0, 'r') ^ fun(x, 18, 0, 'r') ^ fun(x, 41, 0, 'r'));
	if (id == 'e')
		return (fun(x, 28, 0, 'r') ^ fun(x, 34, 0, 'r') ^ fun(x, 39, 0, 'r'));
	if (id == 'S')
		return (fun(x, 19, 0, 'r') ^ fun(x, 61, 0, 'r') ^ (x >> 6));
	if (id == 's')
		return (fun(x, 1, 0, 'r') ^ fun(x, 8, 0, 'r') ^ (x >> 7));
	return (0);
}

static void			fullfil_w(t_word w[80], const char m[128])
{
	int				i;

	i = -1;
	while (++i < 16)
	{
		w[i] = ((((t_word)m[i * 8 + 0]) << 56) & 0xff00000000000000)
				| ((((t_word)m[i * 8 + 1]) << 48) & 0x00ff000000000000)
				| ((((t_word)m[i * 8 + 2]) << 40) & 0x0000ff0000000000)
				| ((((t_word)m[i * 8 + 3]) << 32) & 0x000000ff00000000)
				| ((((t_word)m[i * 8 + 4]) << 24) & 0x00000000ff000000)
				| ((((t_word)m[i * 8 + 5]) << 16) & 0x0000000000ff0000)
				| ((((t_word)m[i * 8 + 6]) << 8) & 0x000000000000ff00)
				| (((t_word)m[i * 8 + 7]) & 0x0000000000000000ff);
	}
	i = 15;
	while (++i < 80)
	{
		w[i] = fun(w[i - 2], 0, 0, 'S') + w[i - 7]
				+ fun(w[i - 15], 0, 0, 's') + w[i - 16];
	}
}

static void			compute_h_copy(t_word h[8], t_word w[80])
{
	int				i;
	t_word			t1;
	t_word			t2;

	i = -1;
	while (++i < 80)
	{
		t1 = h[7] + fun(h[4], 0, 0, 'E') + fun(h[4], h[5], h[6], 'c')
				+ g_sha512_k[i] + w[i];
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

void				sha512_block(t_sha512 *ctx, const char m[128])
{
	t_word			w[80];
	t_word			h_copy[8];

	fullfil_w(w, m);
	ft_memcpy(h_copy, ctx->h, sizeof(t_word) * 8);
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
