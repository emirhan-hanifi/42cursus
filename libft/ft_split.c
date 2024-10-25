/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:00 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/24 23:07:59 by ehabes           ###   ########.fr       */
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

static char     **memory_allocation_process(const char *s, char c, size_t n_substr)
{
    size_t      i;
    char        **str;
    
}

char    **ft_split(char const *s, char c)
{
    unsigned char   **res;
    size_t          i;
    size_t          len;

    if (!s)
        return (NULL);

    
}