/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/06 18:33:36 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdlib.h>

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int nb);
void				ft_putnbr_n(int nb);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_printmemory(void *ptr, int length);
void				ft_putaddr(void *ptr);
void				ft_putdbl(double nb);

int					ft_printf(const char *str, ...);
int					ft_printnchar(int nb, char c);
int					ft_add_buff(char *buf, const char *src,
					size_t buffsize, size_t start);
int					ft_end_buff(char *buf, size_t last);

#endif
