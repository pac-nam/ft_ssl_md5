/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:56:12 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/21 15:48:07 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "memory.h"
#include "printf_srcs.h"
#include "str.h"

/*
**	ft_printf is a variadic function taking in first argument the format that
**	will be printed with flags to precise the type and the number of argument
**	following each flag can contain options. A flag is a letter preceded by
**	the symbol '%'. The options are between '%' and the flag.
**
**	FLAGS:
**		%b: The unsigned int argument is converted to unsigned binary.
**		%o: The unsigned int argument is converted to unsigned octal.
**		%O: Alias for '%llo'.
**		%d: The int argument is converted to signed decimal notation.
**		%i: Alias for '%d'.
**		%D: Alias for '%lld'.
**		%u: The unsigned int argument is converted to unsigned decimal.
**		%U: Alias for '%llu'.
**		%x: The unsigned int argument is converted to unsigned hexadecimal.
**			(using lowercase "abcdef").
**		%X: The unsigned int argument is converted to unsigned hexadecimal
**			(using uppercase "ABCDEF").
**		%c: The int argument is converted to an unsigned char.
**		%C: The wint_t (wide character) argument is converted to a
**			multibyte sequence (unicode). Alias for '%lC'.
**		%s: The const char * argument is expected to be a pointer to an
**			array of character type (pointer to a string).
**		%S: The const wchar_t * argument is expected to be a pointer to
**			an array of wide characters. Alias for '%ls'.
**		%p: The void * pointer argument is printed in hexadecimal.
**		%%: The charactere '%' is printed.
**		%n: The number of characters written so far is stored into the
**			integer indicated by the int * (or variant) pointer
**			argument. No argument is converted.
**	OPTIONS:
**		'#':
**			Used with flags 'x' and 'X' add before the value '0x' or '0X'.
**		' ':
**			(a space) A blank should be left before a positive number
**			(or empty string) produced by a signed conversion.
**		'+':
**			Add a charactere '+' if the number passed is positive.
**			By default a sign is used only for negative numbers.
**			A + overrides a space if both are used.
**		'-':
**			The converted value is to be left adjusted on the field boundary.
**			Option '-' overrides option '0' if both are used.
**		'0':
**			The value is padded on the left with zeros rather than blanks.
**			If options '0' and '-' both appear, the '0' is ignored.
**			If a precision is given with a numeric conversion (d, i, o, u, x,
**			and X), the option '0' is ignored.
**		'.X' (where X is an integer):
**			This option represent the minimal number of digits printed for
**			numerical values. Or the maximal length for strings.
**		'X' (where X is an integer):
**			This option is the minimal width printed by the argument, right
**			adjusted by default.
**		'hh' or 'h' or 'll' or 'l' or 'j' or 'z':
**			This option modify the length of the parameter.
**			'hh' = signed char or unsigned char
**			'h'  = short or unsigned short
**			'll' = long long or unsigned long long
**			'l'  = long or unsigned long
**			'j'  = intmax_t or uintmax_t
**			'z'  = size_t or ssize_t
**
**	EXEMPLES:
**		ft_printf("|%-8.5s", "hello world|\n")
**			output: |hello   |\n
**		ft_printf("|% +12.9ld|",(long)2345678)
**			output: |  +002345678|\n
*/

static int	ft_print_str(const char *format, int *index)
{
	int		i;

	i = ft_strlen_c(&format[*index], '%');
	write(1, &format[*index], i);
	*index += i;
	return (i);
}

static int	ft_printf_next(char *str, va_list ap, int *count)
{
	int			*info;
	int			(*ft_printf_tab[9])(va_list, int*);

	if (!(info = (int*)malloc(sizeof(int) * 10)))
		return (0);
	ft_printf_tab[0] = &ft_printf_s;
	ft_printf_tab[1] = &ft_printf_di;
	ft_printf_tab[2] = &ft_printf_bouxmx;
	ft_printf_tab[3] = &ft_printf_ms;
	ft_printf_tab[4] = &ft_printf_md;
	ft_printf_tab[5] = &ft_printf_p;
	ft_printf_tab[6] = &ft_printf_momu;
	ft_printf_tab[7] = &ft_printf_c;
	ft_printf_tab[8] = &ft_printf_mc;
	ft_take_infos(str, &info);
	if (info[9] == '%' && ft_last_char_index(str) != 0)
		return (*count += ft_printf_modulo(&info));
	else if (info[9] == 'n')
		return (ft_printf_n(ap, *count));
	else if (info[9] != '%')
		*count += (ft_printf_tab[info[8]])(ap, info);
	ft_memdel((void**)&info);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	char		*str;
	va_list		ap;

	i = 0;
	count = 0;
	str = ft_strdup(format);
	va_start(ap, format);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_printf_next(&str[i], ap, &count);
			i = i + ft_printf_pass_str(&str[i]);
		}
		else
			count += ft_print_str(str, &i);
	}
	ft_strdel(&str);
	va_end(ap);
	return (count);
}
