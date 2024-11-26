/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:46:47 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/23 21:13:51 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putnbr(int n)
{
    long num;
    int count;

    count = 0;
    num = n;
    if (n < 0) {
        count += ft_putchr('-');
        num = -num;
    }
    if (num > 9) {
        count += ft_putnbr(num / 10);
    }
    count += ft_putchr((num % 10) + '0');

    return count; 
}