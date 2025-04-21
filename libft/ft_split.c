/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:44:11 by mucankir          #+#    #+#             */
/*   Updated: 2024/11/16 21:06:02 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int	count;
	int	inword;

	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			inword = 1;
			count++;
		}
		else if (*s == c)
			inword = 0;
		s++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static void	free_all(char **split, int i)
{
	while (i-- > 0)
		free(split[i]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		count;

	if (!s)
		return (NULL);
	count = word_counter(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	split[count] = NULL;
	i = 0;
	while (count-- > 0)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (split);
		split[i] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!split[i++])
			return (free_all(split, i - 1), NULL);
		s += ft_wordlen(s, c);
	}
	return (split);
}
