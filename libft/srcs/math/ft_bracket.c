/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:56:38 by exam              #+#    #+#             */
/*   Updated: 2018/08/05 12:23:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_brackets verify the consistency of the brackets.
**	return 1 if it is valid, 0 elseway.
**	WARNING: To optimize the function, the allowed size of the stack is 128.
**	WARNING: ft_brackets can crash if the expression are too heavy.
*/

static int		ft_bracket_charcmp(char c1, char c2)
{
	return ((c1 == '(' && c2 == ')')
			|| (c1 == '{' && c2 == '}')
			|| (c1 == '[' && c2 == ']'));
}

int				ft_brackets(char *str)
{
	int		tab[128];
	int		i;

	tab[0] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			tab[++tab[0]] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!ft_bracket_charcmp(tab[tab[0]--], str[i]))
				return (0);
		++i;
	}
	return (tab[0] == 0);
}
