/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:29:21 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/26 20:17:03 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char    c;

    if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
    }

    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
    }
    
    c = (n % 10) + 48;
    write(fd, &c, 1);
}