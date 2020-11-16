/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_srcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:32:23 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 15:49:24 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_SRCS_H
# define PRINTF_SRCS_H

# include <stdarg.h>

int		ft_printf_di(va_list ap, int *infos);
int		ft_printf_bouxmx(va_list ap, int *infos);
int		ft_printf_momu(va_list ap, int *infos);

int		ft_printf_s(va_list ap, int *infos);
int		ft_printf_mc(va_list ap, int *infos);
int		ft_printf_md(va_list ap, int *infos);
int		ft_printf_ms(va_list ap, int *infos);
int		ft_printf_c(va_list ap, int *infos);
int		ft_printf_p(va_list ap, int *infos);
int		ft_printf_n(va_list ap, int count);

int		ft_printf_modulo(int **info);
int		ft_printf_b(unsigned long long nb, int *infos);
int		ft_printf_o(unsigned long long nb, int *infos);
int		ft_printf_u(unsigned long long nb, int *infos);
int		ft_printf_x(unsigned long long nb, int *infos);
int		ft_printf_mx(unsigned long long nb, int *infos);

int		ft_last_char_index(char *str);
int		ft_printf_pass_str(char *str);
char	ft_last_char(char *str);
void	ft_take_infos(char *format, int **infos);

#endif
