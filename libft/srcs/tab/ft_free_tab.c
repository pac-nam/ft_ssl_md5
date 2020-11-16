/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:53:09 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:42:29 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "tab.h"
#include <stdlib.h>

void			ft_free_tab(char **tab)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = ft_tablen(tab);
	while (i < n)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
