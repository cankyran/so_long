/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:42:20 by mucankir          #+#    #+#             */
/*   Updated: 2024/10/21 04:51:57 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + len_s));
	while (len_s--)
	{
		if (*(s + len_s) == (char)c)
			return ((char *)(s + len_s));
	}
	return (NULL);
}
