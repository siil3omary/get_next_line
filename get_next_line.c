#include "get_next_line.h"
#define BUFFER_SIZE 5

char *read_buffer(int fd ,char *buf)
{
int read_byte;
char *readed_buf;


readed_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
if (!readed_buf)
{
	return (NULL);
}

while (1 != 2)
{
	read_byte = read(fd, readed_buf, BUFFER_SIZE);
	if (read_byte == -1)
		return (NULL);
	read_buffer[read_byte] = '\0';
	if (read_byte == 0)
		break;
	buf = ft_strjoin(buf , readed_buf);
	if (isnewline(buf))
		break;
	
}
free(readed_buf);
return (buf);



}

char *extract_line(char *buf)
{
	char *line;

	int i;
	i = 0;
	if (!buf || ft_strlen(buf) == 0)
	{
		return (NULL);
	}
	while (buf[i] && buf[i] != '\n')
	i++;

	line = ft_substr(buf, 0, i + 1);
	return (line);
	
}

char *new_buf(char *buf)
{
	char *new;
	int buf_lenght;
	if (!buf)
	{
		return (NULL);
	}
	
	buf_lenght = ft_strlen(buf);
		while (buf[i] && buf[i] != '\n')
		i++;
		buf_lenght = i;
		while (buf[buf_lenght])
		{
			buf_lenght++;
		}
		buf_lenght -= i;

	new = ft_substr(buf, i + 1 , buf_lenght);
	 free(buf);
	 return (new);

}

char *get_next_line(int fd)
{
 char *line = NULL;

static char *buf = NULL;

if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	return (NULL);



buf = read_buff(fd , buf);
if(!buf)
return (NULL);
line = extract_line(buf);
buf = new_buf(buf);


return (line);
}
