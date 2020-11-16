/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:41:34 by exam              #+#    #+#             */
/*   Updated: 2018/03/21 13:56:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_intlen_base return the length of the value passed
**	using the base passed in parametre.
**	If value is less than 0 and base is not 10, 0 is returned.
*/

int		ft_intlen_base(int value, int base)
{
	int	len;

	len = 0;
	if (base < 2)
		return (0);
	if (value == 0)
		return (1);
	if (value < 0 && base == 10)
		len++;
	while (value != 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}
