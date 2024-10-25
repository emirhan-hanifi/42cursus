/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:17:24 by ehabes            #+#    #+#             */
/*   Updated: 2024/10/22 21:27:18 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *joined_str;
    size_t  first_str_len;
    size_t  second_str_len;
    
    if (!s1 || !s2)
        return (NULL);
    
    first_str_len = ft_strlen(s1);
    second_str_len = ft_strlen(s2);
    joined_str = (char *)malloc((first_str_len + second_str_len) + 1);

    ft_strlcpy(joined_str, s1, first_str_len);

    ft_strlcat(joined_str, s2, second_str_len);

    return (joined_str);
}