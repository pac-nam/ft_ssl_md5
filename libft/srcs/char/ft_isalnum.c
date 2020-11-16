/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:17:24 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 16:07:11 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
**	ft_isalnum return 1 if the integer passed is a digit or a letter uppercase
**	or lowercase, 0 elseway.
*/

int		ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
