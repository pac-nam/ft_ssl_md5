/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/18 10:30:26 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include <wchar.h>
# include <stdint.h>

# define HEXA "0123456789ABCDEF"

int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
char		*ft_itoa(int n);
char		*ft_itoa_base(int n, int base);
char		*ft_lltoa(long long n);
char		*ft_ulltoa_base(unsigned long long n, int base);
char		*ft_dtoa(double n);
char		*ft_itoa_no_malloc(int n, char *dst);
char		*ft_utoa_base_no_malloc(uint32_t value, char *dst, int base);

int			ft_conv_utf8(int wbytes, wchar_t wchar, char *s);
int			ft_wc_convert(char *s, wchar_t wchar);
int			ft_wcs_convert(char *s, wchar_t *pwcs, int n);
int			ft_intlen_base(int value, int base);
int			ft_intlen(int value);
int			ft_lllen(long long value);

#endif
