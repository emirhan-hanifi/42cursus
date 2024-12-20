/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:36 by ehabes            #+#    #+#             */
/*   Updated: 2024/12/17 14:27:34 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    size_t len;

	len = 0;
    while (str && str[len])
        len++;
    return len;
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t	i;
	size_t	j;

	i = 0;
	j = 0;
    char *result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!result)
        return NULL;
    while (s1 && s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
        result[i++] = s2[j++];
    result[i] = '\0';
    free(s1);
    return result;
}

char *ft_strdup(const char *s)
{
    char *dup;
    size_t i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
    if (!dup)
        return NULL;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char *ft_strchr(const char *s, int c)
{
    size_t i;

	i = 0;
    while (s && s[i])
    {
        if (s[i] == (char)c)
            return (char *)&s[i];
        i++;
    }
    return NULL;
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;

    if (!s || start >= ft_strlen(s))
        return ft_strdup("");
    substr = malloc(len + 1);
    if (!substr)
        return NULL;
    i = 0;
    while (s[start + i] && i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return substr;
}
