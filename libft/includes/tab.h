/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/10/08 12:48:15 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  TAB_H
# define TAB_H

# include <stdlib.h>

void	ft_free_tab(char **tab);
char	**ft_tabnew(size_t size);
char	**ft_tabdup(char **s1);
size_t	ft_tablen(char **s);

#endif
