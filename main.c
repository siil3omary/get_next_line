#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	
	printf("%d\n", fd);
	printf("%s", line);

	
free(line);
	close(fd);
	return (0);
}