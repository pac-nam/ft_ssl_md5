/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:37:11 by tbleuse           #+#    #+#             */
/*   Updated: 2018/08/05 12:33:47 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"
#include "conversion.h"
#include "printf_srcs.h"
#include "str.h"

static int		ft_printf_infos_z_len_pre(int **info, char *str, int max)
{
	int			i;

	i = 0;
	while (!(ft_isdigit(str[i])) && str[i] != '.' && str[i] != 'h'
			&& str[i] != 'l' && str[i] != 'j' && str[i] != 'z' && i < max)
		i++;
	if (str[i] == '0')
		(*info)[1] = 1;
	i = 0;
	while (str[i] == '0' || (!ft_isdigit(str[i]) && str[i] != '.'
			&& str[i] != 'h' && str[i] != 'l' && str[i] != 'j'
			&& str[i] != 'z' && i < max))
		i++;
	if (ft_isdigit(str[i]))
		(*info)[5] = ft_atoi(&str[i]);
	i = 0;
	while (str[i] != '.' && str[i] != 'h' && str[i] != 'l'
			&& str[i] != 'j' && str[i] != 'z' && i < max)
		i++;
	if (str[i] == '.')
		(*info)[6] = (ft_atoi(&str[i + 1]));
	return (1);
}

static int		ft_printf_size(char *str, int max)
{
	int			i;

	i = 0;
	while (str[i] != 'h' && str[i] != 'l'
			&& str[i] != 'j' && str[i] != 'z' && i < max)
		i++;
	if (str[i] == 'h' && str[i + 1] == 'h')
		return (1);
	if (str[i] == 'h')
		return (2);
	if (str[i] == 'l' && str[i + 1] == 'l')
		return (3);
	if (str[i] == 'l')
		return (4);
	if (str[i] == 'j')
		return (5);
	if (str[i] == 'z')
		return (6);
	return (0);
}

static int		ft_printf_type(char c)
{
	char		*str;
	int			i;

	if (c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == 'b')
		return (2);
	if (c == 'U')
		return (6);
	str = "sdoSDpOcCb";
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void			ft_take_infos(char *format, int **info)
{
	int				i;
	int				max;

	i = 0;
	max = ft_last_char_index(format);
	while (i < 8)
		(*info)[i++] = -1;
	if (ft_strnstr(format, "#", max))
		(*info)[0] = 1;
	if (ft_strnstr(format, "-", max))
		(*info)[2] = 1;
	if (ft_strnstr(format, "+", max))
		(*info)[3] = 1;
	if (ft_strnstr(format, " ", max))
		(*info)[4] = 1;
	ft_printf_infos_z_len_pre(info, format, max);
	(*info)[7] = ft_printf_size(format, max);
	(*info)[8] = ft_printf_type(format[max]);
	(*info)[9] = (int)format[max];
	if ((*info)[2] != -1 ||
			((*info)[6] != -1 && !ft_strchr("cCsS%", (*info)[9])))
		(*info)[1] = -1;
	if ((*info)[3] != -1)
		(*info)[4] = -1;
}
