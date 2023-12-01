#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}


char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}




static char	*constr(char const *s1, char const *s2)
{
	size_t	all_len;
	char	*result;
	size_t	i;
	size_t	ri;

	all_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((all_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ri = 0;
	i = 0;
	while (s1[i])
		result[ri++] = s1[i++];
	i = 0;
	while (s2[i])
		result[ri++] = s2[i++];
	result[ri] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1));
		else if (s2)
			return (ft_strdup(s2));
		else
			return (NULL);
	}
	return (constr(s1, s2));
}
int isnewline(char *buf)
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len || len == 0)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}