/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:12:03 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/06 18:22:27 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_m_count_second(int *m_count, int *save)
{
	if (*save == 0)
	{
		*m_count = *m_count + 1;
		*save = 1;
	}
	else
	{
		*m_count = *m_count - 1;
		*save = 0;
	}
}

int				ft_m_count(const char *format)
{
	int		i;
	int		m_count;
	int		save;

	m_count = 0;
	i = 0;
	save = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_m_count_second(&m_count, &save);
		if (format[i] != '%')
			save = 0;
		i++;
	}
	return (m_count);
}
