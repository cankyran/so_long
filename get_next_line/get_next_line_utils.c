/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucankir <mucankir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:58:31 by mucankir          #+#    #+#             */
/*   Updated: 2024/12/15 01:10:59 by mucankir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_check_nl(char *stash)
{
    int i;

    if (!stash)
        return (0);
    i = 0;
    while (stash[i])
    {
        if (stash[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *ft_str_join(char *s1, char *s2)
{
    char *s3;
    int i;
    int j;

    if (!s1)
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if (!s2)
        return (NULL);
    s3 = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
    if (!s3)
        return (free(s1), NULL);
    i = -1;
    while (s1[++i])
        s3[i] = s1[i];
    j = 0;
    while (s2[j])
        s3[i++] = s2[j++];
    s3[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
    return (free(s1), s3);
}

size_t gnl_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
