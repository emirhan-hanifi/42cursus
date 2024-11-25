/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:49:08 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/25 20:58:03 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putunbr(unsigned int n)
{
    int count;

	count = 0;
    if (n >= 10)
        count += ft_putunbr(n / 10);
    count += ft_putchr((n % 10) + '0');
    return count;
}