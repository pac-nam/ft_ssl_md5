/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int				core(int ac, char **av)
{
	t_ssl		ssl;

	if (ac == 1 || !ft_strcmp(av[1], "-h") || !ft_strcmp(av[1], "--help"))
		return (help(NULL, 1));
	ssl.digest = 0;
	ssl.args = 0;
	ssl.type = 0;
	digest(av[1], &ssl);
	check_type(&ssl);
	if (ssl.type & is_md5)
		return (ft_ssl_md5(&ssl, ac, av));
	else if (ssl.type & is_des)
		return (ft_ssl_des(&ssl, av));
	return (1);
}
