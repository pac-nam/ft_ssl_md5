/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_des.h"

void			init_struct_des(t_ssl *ssl, t_ssl_des *des)
{
	des->args = 0;
	des->digest = ssl->digest;
	des->type = ssl->type;
	des->key = 0;
	des->salt = 0;
	des->input_file_fd = -1;
	des->output_file_fd = 1;
	des->break_hash = WRAP;
	des->digest = 0;
}

int				open_error(char *file, int ret)
{
	ft_printf("ft_ssl: %s: %s\n\n", file, NO_SUCH_FILE);
	return (help(NULL, ret));
}

int				parser_des2(t_ssl_des *des, char **av, int *i)
{
	if ((!(ft_strcmp(av[*i], "-b"))
	|| !(ft_strcmp(av[*i], "-w"))) && av[*i + 1])
	{
		des->args |= FLAG_DES_b;
		des->break_hash = ft_atoi(av[*i + 1]);
		(*i)++;
	}
	else
		return (help_des(av[*i], 0));
	return (1);
}

int				parser_des(t_ssl_des *des, char **av)
{
	int			i;

	i = 1;
	while (av[++i])
	{
		if (!(ft_strcmp(av[i], "-a")))
			des->args |= FLAG_DES_a;
		else if (!(ft_strcmp(av[i], "-d")))
			des->args |= FLAG_DES_d;
		else if (!(ft_strcmp(av[i], "-e")))
			des->args |= FLAG_DES_e;
		else if (!(ft_strcmp(av[i], "-i")) && av[i + 1])
		{
			des->args |= FLAG_DES_i;
			if ((des->input_file_fd = open(av[i + 1], O_RDONLY)) < 0)
				return (open_error(av[i + 1], 0));
			i++;
		}
		else if (!(parser_des2(des, av, &i)))
			return (0);
	}
	return (1);
}

int				ft_ssl_des(t_ssl *ssl, char **av)
{
	t_ssl_des	des_struct;

	init_struct_des(ssl, &des_struct);
	if (!(parser_des(&des_struct, av)))
		return (1);
	if (des_struct.args & FLAG_DES_d && des_struct.args & FLAG_DES_e)
		return (help(NULL, 1));
	if (!(des_struct.args & FLAG_DES_e) && !(des_struct.args & FLAG_DES_d))
		des_struct.args |= FLAG_DES_e;
	if (ssl->digest & digest_base64)
		print_base64(&des_struct, base64(&des_struct, HEX));
	return (0);
}
