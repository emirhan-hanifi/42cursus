/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:29:19 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/21 00:40:45 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  d_len;
    size_t  s_len;
    size_t  i;

    d_len = ft_strlen(dst);
    s_len = ft_strlen(src);
    
    if (size <= d_len) return (size + s_len);
    
    i = 0;
    while (i < (d_len - size) - 1 && src[i])
    {
        dst[d_len + i] = src[i];
        i++;
    }
    dst[d_len + i] = '\0';

    return (d_len + s_len);
}