/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:48 by ehabes            #+#    #+#             */
/*   Updated: 2024/12/17 14:29:58 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *extract_line(char **buffer)
{
    char *line;
    char *tmp;
    size_t i = 0;

    if (!*buffer || !**buffer)
        return NULL;
    while ((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    line = ft_substr(*buffer, 0, i + ((*buffer)[i] == '\n' ? 1 : 0));
    tmp = ft_strdup(*buffer + i + ((*buffer)[i] == '\n' ? 1 : 0));
    free(*buffer);
    *buffer = tmp;
    return line;
}

static char *read_and_store(int fd, char *buffer)
{
    char *read_buffer;
    ssize_t bytes_read;

    read_buffer = malloc(BUFFER_SIZE + 1);
    if (!read_buffer)
        return NULL;
    while ((bytes_read = read(fd, read_buffer, BUFFER_SIZE)) > 0)
    {
        read_buffer[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, read_buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(read_buffer);
    return buffer;
}

char *get_next_line(int fd)
{
    static char *buffer;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    buffer = read_and_store(fd, buffer);
    return extract_line(&buffer);
}
