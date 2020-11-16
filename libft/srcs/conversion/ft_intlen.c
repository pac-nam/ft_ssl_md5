/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:41:34 by exam              #+#    #+#             */
/*   Updated: 2018/03/21 13:56:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

/*
**	ft_intlen_base return the length of the value passed in base 10.
*/

int		ft_intlen(int value)
{
	return (ft_intlen_base(value, 10));
}
