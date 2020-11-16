/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/07 11:05:16 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

int		ft_random(void);
int		ft_sqrt(int nb);
int		ft_bracket(char *str);
int		ft_power(int number, int power);
int		*ft_sort_int_tab(int *tab, size_t length);
int		ft_abs(int nb);
int		ft_biggest(int a, int b);
int		ft_smallest(int a, int b);

#endif
