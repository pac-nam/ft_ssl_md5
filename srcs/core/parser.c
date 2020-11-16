#include "ft_ssl.h"

int				parse_arg2(char **av, size_t *i, t_ssl *ssl)
{
	if (!ft_strcmp(av[*i], "-s"))
	{
		if (!av[*i + 1])
			return (help(NULL, 0));
		ssl->args |= FLAG_s;
		*i += 1;
		if (!(ssl->opt.args_s[ssl->nb_arg_s] = ft_strdup(av[*i])))
			return (0);
		ssl->nb_arg_s++;
	}
	return (1);
}

size_t			parse_arg(char **av, t_ssl *ssl)
{
	size_t		i;

	i = 2;
	while (av[i])
	{
		if (av[i][0] != '-')
			return (i);
		if (!ft_strcmp(av[i], "-p"))
			ssl->args |= FLAG_p;
		else if (!ft_strcmp(av[i], "-q"))
			ssl->args |= FLAG_q;
		else if (!ft_strcmp(av[i], "-r"))
			ssl->args |= FLAG_r;
		else if (!(parse_arg2(av, &i, ssl)))
			return (0);
		i++;
	}
	return (i);
}

int				parser(char **av, t_ssl *ssl)
{
	size_t		i;

	if (!(digest(av[1], ssl)))
		return (0);
	if (!(i = parse_arg(av, ssl)))
		return (0);
	return (i);
}
