/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:57:04 by mucankir          #+#    #+#             */
/*   Updated: 2024/11/29 01:02:17 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_unsigned(n / 10);
	len += ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_hex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_hex(n / 16, c);
	if (c == 'x')
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	if (c == 'X')
		len += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_point(unsigned long n, int i)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (i == 1)
		len += ft_putstr("0x");
	i = 0;
	if (n >= 16)
		len += ft_point((n / 16), i);
	len += write(1, &"0123456789abcdef"[n % 16], 1);
	return (len);
}
