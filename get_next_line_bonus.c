/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:06 by ehabes            #+#    #+#             */
/*   Updated: 2024/12/17 16:23:17 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

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
    char *read_buffer = malloc(BUFFER_SIZE + 1);
    ssize_t bytes_read;

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
    static char *buffers[OPEN_MAX]; // Her fd için bir buffer
    if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
        return NULL;
    buffers[fd] = read_and_store(fd, buffers[fd]);
    return extract_line(&buffers[fd]);
}
