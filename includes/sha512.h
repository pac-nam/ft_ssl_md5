/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/19 12:33:50 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHA512_H
# define __SHA512_H

# include "../libft/includes/libft.h"
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BASE "0123456789abcdef"

typedef uint64_t	t_word;

/*
**	add this prototypes in the header
**	char			*sha512(const char *m)
**	char			*sha512_fd(const int fd)
**	char			*sha512_size(const char *m, size_t length);
*/

typedef struct	s_sha512 {
	t_word		h[8];
	uint64_t	l;
	uint64_t	tmpl;
}				t_sha512;

t_word			rotrn(t_word x, t_word n);
t_word			ch(t_word x, t_word y, t_word z);
t_word			maj(t_word x, t_word y, t_word z);
t_word			sigma_maj(t_word x, t_word n);
t_word			sigma_min(t_word x, t_word n);

void			sha512_block(t_sha512 *ctx, const char m[128]);
char			*sha512_h_to_string(t_sha512 *ctx, char *result);

#endif
