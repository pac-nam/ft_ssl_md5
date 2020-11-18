/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/19 12:33:50 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHA256_H
# define __SHA256_H

# include "../libft/includes/libft.h"
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BASE "0123456789abcdef"

typedef uint32_t	t_word;

/*
**	add this prototypes in the header
**	char			*sha256(const char *m)
**	char			*sha256_fd(const int fd)
**	char			*sha256_size(const char *m, size_t length);
*/

typedef struct		s_sha256 {
	t_word			h[8];
	uint64_t		l;
	uint64_t		tmpl;
}					t_sha256;

uint32_t			rotrn(uint32_t x, uint32_t n);
uint32_t			ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t			maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t			sigma_maj(uint32_t x, uint32_t n);
uint32_t			sigma_min(uint32_t x, uint32_t n);

void				sha256_block(t_sha256 *ctx, const char m[64]);
char				*sha256_h_to_string(t_sha256 *ctx, char *result);

#endif
