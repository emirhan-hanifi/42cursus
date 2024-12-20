/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:06:51 by ehabes            #+#    #+#             */
/*   Updated: 2024/12/17 16:06:52 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_substr(char *s, unsigned int start, size_t len);

#endif
