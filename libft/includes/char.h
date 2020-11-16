/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/19 12:33:50 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

#include <stdlib.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isxdigit(int c);
int			ft_isalnum(int c);
int			ft_isspace(int c);
int			ft_isascii(int c);
int			ft_ispunct(int c);
int			ft_iscntrl(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_charcatindex(char *buf, size_t *index, const char c);

#endif
