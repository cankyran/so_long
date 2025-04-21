/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:42:52 by mucankir          #+#    #+#             */
/*   Updated: 2024/11/07 19:01:56 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	i = 0;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (*(s + start) && len-- > 0)
	{
		sub[i] = *(s + start);
		i++;
		s++;
	}
	sub[i] = '\0';
	return (sub);
}
