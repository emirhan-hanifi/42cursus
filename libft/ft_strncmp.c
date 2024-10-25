/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:25:57 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/20 18:17:30 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;
    
    i = 0;
    while (i < n - 1 && (*s1 || *s2))
    {
        if (s1[i] != s2[i])
        {
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
        i++;
    }
    return (0);
}