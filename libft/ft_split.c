/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:00 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/25 22:49:53 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  substr_count(const char *s, char c)
{
    size_t  in_substr;
    size_t  n_substr;

    in_substr = 0;
    n_substr = 0;

    while (*s)
    {
        if (*s != c && !in_substr)
        {
            n_substr++;
            in_substr = 1;
        }
        else if (*s == c)
        {
            in_substr = 0;
        }
        s++;
    }
    return (n_substr);
}

static void f_clean(char **str, size_t n_substr)
{
    while (n_substr > 0)
    {
        free(str[n_substr - 1]);
        n_substr--;
    }
    free(str);
}

static char **memory_allocation_process(const char *s, char c, size_t n_substr)
{
    size_t      sub_len;
    size_t      i;
    size_t      in_substr;
    char        **str;
    
    str = (char **)malloc((n_substr + 1) * sizeof(char *));
    if (!str)
        return (NULL);

    in_substr = 0;
    i = 0;
    sub_len = 0;
    while (*s && i < n_substr)
    {
        if (*s != c && !in_substr)
        {
            in_substr = 1;
            sub_len = 0;
        }

        if (*s != c)
            sub_len++;

        if ((*s == c || *(s + 1) == '\0') && in_substr)
        {
            str[i] = (char *)malloc(sub_len + 1);
            if (!str[i])
            {
                f_clean(str, i);
                return (NULL);
            }
            ft_strlcpy(str[i], s - sub_len + 1, sub_len + 1);
            i++;
            in_substr = 0;
        }
        s++;
    }
    str[i] = NULL;
    return (str);
}

static void split_into_substr(const char *s, char c, char **str, size_t n_substr)
{
    size_t      in_substr;
    size_t      i;
    size_t      j;
    
    i = 0;
    j = 0;
    in_substr = 0;
    while (i < n_substr && *s)
    {
        if (*s != c && !in_substr)
        {
            in_substr = 1;
        }
        
        if (*s != c)
        {
            str[i][j++] = *s;
        }
        
        if (*s == c && in_substr)
        {
            str[i][j] = '\0';
            in_substr = 0;
            i++;
            j = 0;
        }
        s++;        
    }

    if (in_substr)
        str[i][j] = '\0';
}

char    **ft_split(char const *s, char c)
{
    char        **str;
    size_t      n_substr;

    if (!s)
        return (NULL);    

    n_substr = substr_count(s, c);
    str = memory_allocation_process(s, c, n_substr);
    if (!str)
        return (NULL);

    split_into_substr(s, c, str, n_substr);

    return (str);
}
