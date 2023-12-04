#include "get_next_line_bonus.h"

char	*read_buffer(int fd, char *buf)
{
    char	*readed_buf;
    ssize_t	read_byte;
    char	*tmp;

    readed_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!readed_buf)
        return (NULL);
    while (1)
    {
        read_byte = read(fd, readed_buf, BUFFER_SIZE);
        if (read_byte == -1)
            return (NULL);
        readed_buf[read_byte] = '\0';
        if (read_byte == 0)
            break ;
        tmp = ft_strjoin(buf, readed_buf);
        free(buf);
        buf = tmp;
        if (isnewline(readed_buf))
            break ;
    }
    free(readed_buf);
    return (buf);
}

char	*extract_line(char *buf)
{
    char	*line;
    int		i;

    i = 0;
    if (!buf)
        return (NULL);
    if (!ft_strlen(buf))
        return (NULL);
    while (buf[i] && buf[i] != '\n')
        i++;
    line = ft_substr(buf, 0, i + 1);
    if (!line)
        return (NULL);
    return (line);
}

char	*new_buf(char *buf)
{
    char	*new;
    int		buf_length;
    int		i;

    if (!buf)
        return (NULL);
    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    buf_length = 0;
    while (buf[i + buf_length])
        buf_length++;
    new = ft_substr(buf, i + 1, buf_length);
    free(buf);
    return (new);
}

int	isnewline(char *buf)
{
    int	i;

    i = 0;
    while (buf[i])
    {
        if (buf[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char	*get_next_line(int fd)
{
    char		*line;
    static char	*buf[MAX_FD] = {NULL};

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX || fd > MAX_FD)
        return (NULL);
    buf[fd] = read_buffer(fd, buf[fd]);
    if (buf[fd] == NULL)
    {
        free(buf[fd]);
        return (NULL);
    }
    if (!*buf[fd])
    {
        free(buf[fd]);
        return (NULL);
    }
    line = extract_line(buf[fd]);
    if (line == NULL)
    {
        free(line);
        return (NULL);
    }
    buf[fd] = new_buf(buf[fd]);
    if (buf[fd] == NULL)
    {
        free(line);
        return (NULL);
    }
    return (line);
}