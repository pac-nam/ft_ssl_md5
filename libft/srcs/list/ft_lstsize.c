/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:55:31 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 15:02:01 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
**	ft_lstsize return the number of element in the list passed in parameter.
*/

int		ft_lstsize(t_list *begin_list)
{
	t_list	*tmp;
	int		i;

	tmp = begin_list;
	i = 0;
	while (tmp && ++i)
		tmp = tmp->next;
	return (i);
}
