/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:03:55 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:50:35 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "memory.h"
#include "str.h"

/*
**	ft_gnl read a file and return it line by line on each call.
**	Do not use it on multiple file descriptor at the same time.
**	1 is returned if gnl succes.
**	0 is returned if the end of file is reached.
**	-1 is returned in case of error.
**	WARNING: ft_gnl use malloc. So it need to be free to avoid leaks.
*/

static int			ft_read_gnl(const int fd, char **str)
{
	char				buf[GNL_BUFF_SIZE + 1];
	char				*tmp;
	int					ret;

	if (*str && ft_strchr(*str, '\n'))
		return (1);
	while ((ret = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*str && !(*str = ft_strdup(buf)))
			return (-1);
		else
		{
			tmp = *str;
			if (!(*str = ft_strjoin(*str, buf)))
				return (-1);
			ft_strdel(&tmp);
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int					ft_gnl(const int fd, char **line)
{
	static char		*str = NULL;
	char			*tmp;
	int				ret;

	if (fd < 0 || !line || (ret = ft_read_gnl(fd, (&str))) < 0)
		return (-1);
	if (ret == 0 && !(str))
		return (0);
	if (!(*line = ft_strsub(str, 0, ft_strlen_c(str, '\n'))))
		return (-1);
	tmp = str;
	if (!(str = ft_strsub(tmp, ft_strlen_c(tmp, '\n') + 1,
					(ft_strlen(tmp) - ft_strlen_c(tmp, '\n')))))
		return (-1);
	ft_strdel(&tmp);
	if (str[0] == '\0')
		ft_strdel(&str);
	return (1);
}
