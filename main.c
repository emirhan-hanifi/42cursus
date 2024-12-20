#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY); // Dosya adınıza göre değiştirin
    if (fd == -1)
    {
        printf("Dosya açılamadı\n");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Her satır için belleği serbest bırak
    }

    close(fd);
    return 0;
}