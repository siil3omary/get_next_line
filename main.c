#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("%s\n", line); // Expected output: "This is line 1."
    free(line);

    close(fd);
    return 0;
}