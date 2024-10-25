/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:16:19 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/21 23:00:23 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    size_t          i;
    unsigned char   *buff;

    buff = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        buff[i++] = '\0';
    }
}