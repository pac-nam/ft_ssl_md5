/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sha512.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			print_sha512_fd0(t_ssl *ssl)
{
	char		*hash;

	hash = sha512_size(ssl->line, ssl->size_line);
	if (ssl->args & FLAG_p)
		ft_putstr(ssl->line);
	ft_putendl(hash);
	if (ft_strcmp("ERROR", hash))
		ft_strdel(&hash);
}

void			print_sha512_file(const char *file, const short flags)
{
	int			fd;
	char		*hash;

	if ((fd = open(file, O_RDONLY)) < 1)
	{
		ft_printf("sha512: %s: No such file or directory\n", file);
		return ;
	}
	if (!(hash = sha512_fd(fd)))
		hash = "ERROR";
	close(fd);
	if (flags & FLAG_q)
		ft_putendl(hash);
	else if (flags & FLAG_r)
		ft_printf("%s %s\n", hash, file);
	else
		ft_printf("SHA512 (%s) = %s\n", file, hash);
	if (ft_strcmp("ERROR", hash))
		ft_strdel(&hash);
}

void			print_sha512(const char *msg, const short flags)
{
	char		*hash;

	if (!(hash = sha512(msg)))
		hash = "ERROR";
	if (flags & FLAG_q)
		ft_putendl(hash);
	else if (flags & FLAG_r)
		ft_printf("%s \"%s\"\n", hash, msg);
	else
		ft_printf("SHA512 (\"%s\") = %s\n", msg, hash);
	if (ft_strcmp("ERROR", hash))
		ft_strdel(&hash);
}

void			compute_sha512(t_ssl *ssl)
{
	size_t		i;

	i = 0;
	if (ssl->args & FLAG_p || (!(ssl->args & FLAG_s) && !ssl->files))
		read_file(0, ssl);
	if (ssl->args & FLAG_s)
	{
		while (ssl->opt.args_s[i])
		{
			print_sha512(ssl->opt.args_s[i], ssl->args);
			i++;
		}
	}
	i = 0;
	if (ssl->files)
		while (ssl->files[i])
		{
			print_sha512_file(ssl->files[i], ssl->args);
			++i;
		}
}
