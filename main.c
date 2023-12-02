#include "get_next_line.h"

int main() {
    int fd = open("text.txt", O_RDONLY);
    char *s;
    int i = 0;
    while (i < 3) {
        s = get_next_line(fd);
        if (s) {
            printf("%s", s);
            free(s); 
        }
        i++;
    }

    return (0);
}