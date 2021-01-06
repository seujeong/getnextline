#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("/test.txt", O_RDONLY);
	if (fd == -1)
		return 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
			printf("%s\n", line);
		free(line);
	}
	get_next_line(fd, &line);
		printf("%s\n", line);
	close(fd);
	return (0);
}
