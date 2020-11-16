/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:32:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:20:20 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	If a lower letter is passed to ft_tolower, the letter is capitalized.
**	Elseway, the integer passed in argument is returned.
*/

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
