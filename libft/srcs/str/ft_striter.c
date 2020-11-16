/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:29:54 by tbleuse           #+#    #+#             */
/*   Updated: 2018/11/09 12:53:46 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_striter apply the function passed in parameter on
**	each character of the string s.
*/

void		ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(&(*s++));
}
