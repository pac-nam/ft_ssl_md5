/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int				add_files(t_ssl *ssl, char **av, int ac, int start)
{
	if (!av)
		return (1);
	if (ac == start)
		return (1);
	if (!(ssl->files = ft_tabdup(av)))
		return (0);
	return (1);
}

void			calcargs_s(char **av, t_ssl *ssl)
{
	int			i;

	i = 2;
	while (av[i])
	{
		if (av[i][0] != '-')
			break ;
		if (!(ft_strcmp(av[i], "-s")))
		{
			ssl->nb_args_s++;
			i += 2;
		}
		else
			i++;
	}
}
