/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_h_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

static char		*ft_ultoa_base_sha512(uint64_t nb, char *res)
{
	res[0] = BASE[nb >> 60 & 0xf];
	res[1] = BASE[nb >> 56 & 0xf];
	res[2] = BASE[nb >> 52 & 0xf];
	res[3] = BASE[nb >> 48 & 0xf];
	res[4] = BASE[nb >> 44 & 0xf];
	res[5] = BASE[nb >> 40 & 0xf];
	res[6] = BASE[nb >> 36 & 0xf];
	res[7] = BASE[nb >> 32 & 0xf];
	res[8] = BASE[nb >> 28 & 0xf];
	res[9] = BASE[nb >> 24 & 0xf];
	res[10] = BASE[nb >> 20 & 0xf];
	res[11] = BASE[nb >> 16 & 0xf];
	res[12] = BASE[nb >> 12 & 0xf];
	res[13] = BASE[nb >> 8 & 0xf];
	res[14] = BASE[nb >> 4 & 0xf];
	res[15] = BASE[nb >> 0 & 0xf];
	return (res);
}

char			*sha512_h_to_string(t_sha512 *ctx, char *result)
{
	int			i;

	i = -1;
	ft_memset(result, '0', 128);
	while (++i < 8)
		ft_ultoa_base_sha512(ctx->h[i], &(result[i * 16]));
	result[128] = '\0';
	return (result);
}
