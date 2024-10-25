/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:48:33 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/20 18:17:23 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char    *ptr;
    size_t  i;

    ptr = NULL;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            ptr = (char *)&s[i];
            break;
        }
        i++;
    }
    return (ptr);
}