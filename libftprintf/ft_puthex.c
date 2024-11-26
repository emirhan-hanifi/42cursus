/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:49:53 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/26 15:25:48 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_puthex(unsigned int n, unsigned char x)
{
	char	*hex_digits; 
	char	buffer[11];
	int		i;
	int count;
	
    hex_digits = (x) ? "0123456789ABCDEF" : "0123456789abcdef";
	
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