/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:39:45 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/21 01:25:43 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putstr(char *str)
{
    int count;

    if (!str)
        return (-1);
    count = 0;
    while (*str)
    {
        if (ft_putchr(*str++) == -1)
            return (-1);
        count++;
    }
    return (count);
}