#ifndef GET_NEXT_LINE_H 
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>


char *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int isnewline(char *buf);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif // GET_NEXT_LINE_H
