/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:10:52 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 14:04:37 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
**	ft_lstmap apply the function passed in parameter on a copy of
**	each element a the list. The first element of this copy is returned.
**	WARNING: ft_itoa use malloc. So it need to be free to avoid leaks.
**	WARNING: malloc can fail in this case, NULL is returned.
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;

	if (lst == NULL)
		return (NULL);
	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_elem = (f)(lst);
	if (lst->next != NULL)
		new_elem->next = ft_lstmap(lst->next, (f));
	else
		new_elem->next = NULL;
	return (new_elem);
}
