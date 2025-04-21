/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:57:00 by mucankir          #+#    #+#             */
/*   Updated: 2024/11/29 02:33:42 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_hex(va_arg(args, unsigned long), c);
	else if (c == 'p')
		len += ft_point(va_arg(args, unsigned long), 1);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

static int	ft_flag(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%');
}

static int	ft_state(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && !ft_flag(s[i + 1]) && s[i + 1] != '\0')
			return (1);
		else if (s[i] == '%' && s[i + 1] == '\0' && s[i - 1] != '%')
			return (2);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;
	int		n;
	int		i;

	i = 0;
	n = ft_state(format);
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_flag(format[i + 1]))
		{
			i++;
			len += ft_format(format[i], args);
		}
		else if (format[i] == '%' && n == 2)
			return (-1);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
