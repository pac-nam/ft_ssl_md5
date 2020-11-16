/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:43:25 by tbleuse           #+#    #+#             */
/*   Updated: 2018/08/05 12:20:50 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_atoll take a string in parameter and convert it to long long.
**	If the string does not start with digit, '+' or '-', 0 is returned.
**	If in the string there is a non digit charactere, ft_atoll will stop.
**	Be careful, ft_atoll can overflow.
*/

long long		ft_atoll(const char *str)
{
	long long		nb;
	int				is_neg;
	int				i;

	nb = 0;
	is_neg = 1;
	i = 0;
	while (str[i] == '\r' || str[i] == '\v' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10;
		nb = nb + ((int)str[i] - '0');
		i++;
	}
	return (nb * is_neg);
}
