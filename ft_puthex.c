/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:49:53 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/25 23:02:15 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_puthex(unsigned int n, unsigned char x)
{
    char	*hex_dig_u; 
    char	*hex_dig_d;
	char	*hex_digits; 
	char	buffer[11];
	int		i;
	int count;
	
    hex_dig_u = "0123456789ABCDEF";
	hex_dig_d = "0123456789abcdef";
    hex_digits = (x == 'x') ? hex_dig_d : hex_dig_u;
	
	if (n == 0)
	{
		ft_putchr('0');
		return (1);
	}
	i = 0;
	count = 0;
    while (n > 0)
	{
		buffer[i++] = hex_digits[n % 16];
		n /= 16;
	}
	while (--i >= 0)
	{
		count += ft_putchr(buffer[i]);
	}
	return (count);
}