/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:00:59 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/20 18:17:33 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *stack, const char *need, size_t n)
{
    size_t  i;
    size_t  j;

    if (!*need)
        return ((char *)stack);
    
    i = 0;
    while (i < n && *stack)
    {
        j = 0;
        while (stack[i + j] && need[j] && i + j < n && stack[i + j] == need[j])
            j++;
        if (!need[j])
        {
            return ((char *)&stack[i]);
        }
        
        i++;
    }
    return (NULL);
}