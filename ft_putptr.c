/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:48:36 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/25 23:04:44 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdint.h>

int ft_putptr(void *ptr)
{
        uintptr_t   address;
        char        *hex_digit;
        char        buffer[20];
        int         len;
        int         i;
        
        hex_digit = "0123456789abcdef";
        address = (uintptr_t)ptr;
        if (!ptr)
            return ft_putstr("(nil)");
        buffer[0] = '0';
        buffer[1] = 'x';
        i = 0;
        len = 2;
        while (address > 0)
        {
            buffer[19 - i++] = hex_digit[address % 16];
            address /= 16;
        }        
        while (i-- > 0)
            buffer[len++] = buffer[19 - i];
        return (write(1, buffer, len)); 
}