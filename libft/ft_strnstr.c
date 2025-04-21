/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:41:41 by mucankir          #+#    #+#             */
/*   Updated: 2024/11/11 00:00:40 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	size_t		i;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		h = haystack;
		n = needle;
		while (*n && *h == *n && (i + (n - needle)) < len)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
