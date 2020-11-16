/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:54:38 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:24:04 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_sort_int_tab the integer array sorted by increasing order.
**	the sort used is a bubble sort. It is not optimized.
*/

int		*ft_sort_int_tab(int *tab, size_t length)
{
	size_t	index;
	int		tmp;

	index = 0;
	if (length < 2)
		return (tab);
	while (index < length - 1)
	{
		if (tab[index] > tab[index + 1])
		{
			tmp = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = tmp;
			index = 0;
		}
		++index;
	}
	return (tab);
}
