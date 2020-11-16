/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:35:33 by tbleuse           #+#    #+#             */
/*   Updated: 2018/08/05 12:33:51 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_char_index search in the string str the first occurence
**	of the charactere c, and return it index.
**	ft_char_index return -1 if the character c is not found.
*/

int			ft_char_index(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	if (!str[i] && c)
		return (-1);
	return (i);
}
