#include "get_next_line_bonus.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("dene.txt", O_RDONLY);
	fd2 = open("dene2.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line : %s", line);
		free(line);
		line = get_next_line(fd2);
		printf("line : %s", line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}