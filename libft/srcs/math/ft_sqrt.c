/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:53:59 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:27:12 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_sqrt return the square root of the number passed in parameter rounded up.
*/

int		ft_sqrt(int nb)
{
	int		x;

	x = 1;
	if (nb < 0 || nb > 2147395600)
		return (0);
	while (nb > (x * x))
		x++;
	return (x);
}
