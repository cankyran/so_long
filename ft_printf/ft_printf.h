/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:57:13 by mucankir          #+#    #+#             */
/*   Updated: 2024/11/29 01:00:51 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_unsigned(unsigned int n);
int	ft_hex(unsigned int n, char c);
int	ft_putstr(char *str);
int	ft_point(unsigned long n, int i);
int	ft_putchar(int a);

#endif