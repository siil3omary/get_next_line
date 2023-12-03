#include "get_next_line.h"
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY); // Replace "test.txt" with the path to your test file
	if (fd == -1)
	{
		printf("Failed to open the file.\n");
		return 1;
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	close(fd);

	return 0;
}