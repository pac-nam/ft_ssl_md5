/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			init_struct(t_ssl *ssl)
{
	ssl->args = 0;
	ssl->nb_arg_s = 0;
	ssl->nb_args_s = 0;
	ssl->opt.args_s = NULL;
	ssl->files = NULL;
	ssl->size_line = 0;
	ssl->line = NULL;
}

int				ft_ssl_md5(t_ssl *ssl, int ac, char **av)
{
	int			i;

	init_struct(ssl);
	calcargs_s(av, ssl);
	if (ssl->nb_args_s > 0)
		if (!(ssl->opt.args_s = ft_tabnew(ssl->nb_args_s + 1)))
			return (1);
	if (!(i = parser(av, ssl)))
	{
		free_and_exit(ssl);
		return (1);
	}
	if (!(add_files(ssl, av + i, ac, i)))
		return (1);
	check_type(ssl);
	return (run(ssl));
}
