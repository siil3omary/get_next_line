#include "get_next_line.h"

char *get_next_line(int fd)
{
static char *line = NULL;


if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	return (NULL);




}