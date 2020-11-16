/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:41:34 by exam              #+#    #+#             */
/*   Updated: 2019/03/21 13:56:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_lllen return the length of the value passed in base 10.
*/

int		ft_lllen(long long value)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		len++;
	while (value > 0)
	{
		value = value / 10;
		len++;
	}
	return (len);
}
