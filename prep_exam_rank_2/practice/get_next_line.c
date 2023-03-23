
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int i = 0;
	int len = ft_strlen(str);
	char *dup;

	dup = malloc(sizeof(len + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	int		i = -1;
	int		rb;
	char	buffer;
	char	str[1000000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rb = read(fd, &buffer, 1);
	while (rb > 0)
	{
		str[++i] = buffer;
		if (buffer == '\n')
			break ;
		rb = read(1, &buffer, 1);
		i++;
	}
	str[i] = '\0';
	if (rb <= 0 || i == 0)
		return (NULL);
	return (ft_strdup(str));
}
