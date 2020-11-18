/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_h_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

static char		*ft_utoa_base_sha256(uint32_t nb, char *res)
{
	res[0] = BASE[nb >> 28 & 0xf];
	res[1] = BASE[nb >> 24 & 0xf];
	res[2] = BASE[nb >> 20 & 0xf];
	res[3] = BASE[nb >> 16 & 0xf];
	res[4] = BASE[nb >> 12 & 0xf];
	res[5] = BASE[nb >> 8 & 0xf];
	res[6] = BASE[nb >> 4 & 0xf];
	res[7] = BASE[nb >> 0 & 0xf];
	return (res);
}

char			*sha256_h_to_string(t_sha256 *ctx, char *result)
{
	int			i;

	i = -1;
	ft_memset(result, '0', 64);
	while (++i < 8)
		ft_utoa_base_sha256(ctx->h[i], &(result[i * 8]));
	result[64] = '\0';
	return (result);
}
