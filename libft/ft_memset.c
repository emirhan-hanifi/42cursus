/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:42:40 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/26 21:44:59 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    size_t           i;
    unsigned char    *ptr;
    
    ptr = (unsigned char *)s;
    i = 0;
    while (i < n && ptr[i])
    {
        ptr[i++] = (unsigned char)c;
    }
    return (ptr);
}