/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:10:18 by tbleuse           #+#    #+#             */
/*   Updated: 2018/08/05 12:20:18 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_isxdigit return 1 if the integer passed is valid in hexadecimal notation,
**	0 elseway. Reminder: hexa="0123456789ABCDEF" also lowercase is valid.
*/

int		ft_isxdigit(int c)
{
	if ((c >= '0' && c <= '9')
			|| (c >= 'A' && c <= 'F')
			|| (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}
