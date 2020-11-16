/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 08:12:45 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 14:58:37 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
**	ft_lstrev reverse element in the list passed in parameter.
*/

void		ft_lstrev(t_list **begin_list)
{
	t_list		*tmp;
	int			cpt;
	int			i;

	cpt = ft_lstsize(*begin_list) + 1;
	while (--cpt > 0)
	{
		i = -1;
		tmp = *begin_list;
		begin_list = &tmp->next;
		while (++i < cpt)
			tmp = tmp->next;
	}
}
