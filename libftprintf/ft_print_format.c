/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:47:13 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/26 15:26:33 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_value(va_list args, char format)
{
    if (format == 'c')
        return (ft_putchr(va_arg(args, int)));
    else if (format == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (format == 'd' || format == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (format == 'u')
        return (ft_putunbr(va_arg(args, unsigned int)));
    else if (format == 'x')
        return (ft_puthex(va_arg(args, unsigned int), 0));
    else if (format == 'X')
        return (ft_puthex(va_arg(args, unsigned int), 1));
    else if (format == 'p')
        return (ft_putptr(va_arg(args, void *)));
    else if (format == '%')
        return (ft_putchr('%'));
    return (0);
}

int	ft_print_format(va_list args, char format)
{
    return (print_value(args, format));
}