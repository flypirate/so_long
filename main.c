#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 1)
	{
		write(2, "Error at opening file", 21);
		return (1);
	}
	line = get_next_line(fd);
	//printf("%s", line);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}