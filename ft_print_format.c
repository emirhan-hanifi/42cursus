/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:47:13 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/25 22:50:05 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int  print_char(va_list args);
static int  print_string(va_list args);
static int  print_integer(va_list args);
static int  print_unsigned(va_list args);
static int  print_hex(va_list args);
static int  print_pointer(va_list args);
static int  print_percent(va_list args);

static int  (*g_print_funcs[256])(va_list) = { NULL };

void init_print_funcs(void)
{
    g_print_funcs['c'] = print_char;
    g_print_funcs['s'] = print_string;
    g_print_funcs['d'] = print_integer;
    g_print_funcs['i'] = print_integer;
    g_print_funcs['u'] = print_unsigned;
    g_print_funcs['x'] = print_hex;
    g_print_funcs['X'] = print_hex;
    g_print_funcs['p'] = print_pointer;
    g_print_funcs['%'] = print_percent;
}

int ft_print_format(va_list args, char format)
{
    static int initialized = 0;

    if (!initialized)
    {
        init_print_funcs();
        initialized = 1;
    }

    if (!g_print_funcs[(unsigned char)format])
        return (0);

    return g_print_funcs[(unsigned char)format](args);
}

int print_char(va_list args)
{
    return ft_putchr(va_arg(args, int));
}

int print_string(va_list args)
{
    return ft_putstr(va_arg(args, char *));
}

int print_integer(va_list args)
{
    return ft_putnbr(va_arg(args, int));
}

int print_unsigned(va_list args)
{
    return ft_putunbr(va_arg(args, unsigned int));
}

int print_hex(va_list args)
{
    unsigned int value = va_arg(args, unsigned int);
    int is_upper = va_arg(args, int);
    return ft_puthex(value, is_upper);
}

int print_pointer(va_list args)
{
    return ft_putptr(va_arg(args, void *));
}

int print_percent(va_list args)
{
    (void)args;
    return ft_putchr('%');
}
