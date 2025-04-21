/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:37:21 by mucankir          #+#    #+#             */
/*   Updated: 2024/11/16 20:40:38 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*int_s1;
	unsigned char 	*int_s2;

	int_s1 = (char *)s1;
	int_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*int_s1 != *int_s2)
			return (*int_s1 - *int_s2);
		int_s1++;
		int_s2++;
	}
	return (0);
}
