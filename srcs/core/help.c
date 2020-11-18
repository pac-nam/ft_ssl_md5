/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			help(char *arg, int ret)
{
	if (arg)
		ft_printf("ft_ssl: '%s' is not valid\n\n", arg);
	ft_printf("ft_ssl: [DIGEST] [OPTIONS]\n\n");
	ft_printf("Standard commands:\n\nMessage Digest commands:\n");
	ft_printf("%s\n\n", FT_SSL_MD5);
	ft_printf("Cipher commands:\n\n");
	ft_printf("[OPTIONS] (ft_ssl_md5):\n\n");
	ft_printf("-p: echo STDIN to STDOUT and append the checksum to STDOUT.\n");
	ft_printf("-q: quiet mode.\n");
	ft_printf("-r: reverse the format of the output.\n");
	ft_printf("-s: print the sum of the given string.\n\n");
	ft_printf("[OPTIONS] (base64):\n\n");
	ft_printf("-a: decode/encode the input/output in base64, depending on the"
		" encrypt mode\n");
	ft_printf("-b, -w: break encoded string into num character lines\n");
	ft_printf("-d, decrypt mode\n");
	ft_printf("-e, encrypt mode (default)\n");
	return (ret);
}

void		free_and_exit(t_ssl *ssl)
{
	if (ssl->opt.args_s)
		ft_free_tab(ssl->opt.args_s);
	if (ssl->files)
		ft_free_tab(ssl->files);
}
