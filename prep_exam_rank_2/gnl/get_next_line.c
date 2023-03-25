/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/25 14:54:38 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/03/25 18:58:11 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// -D BUFFER_SIZE=n
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out
void	free_ptr(char **ptr);
char	*ft_strndup(const char *str, size_t n);
char	*join_line(int start, char **buffer_holder);
char	*read_line(int	fd, char **buffer_holder, char *curr_buffer);

char	*get_next_line(int fd)
{
	char		*curr_buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	curr_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (curr_buffer == NULL)
	{
		return (NULL);
	}
	bytes_read = read(fd, curr_buffer, BUFFER_SIZE + 1);
	if (bytes_read == -1)
	{
		return (NULL);
	}
	return (curr_buffer);
}

int main(void)
{
	char	*line;
	int		fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (-1);
	}
	line = get_next_line(fd);
	for (int i = 0; i < 3; i++)
	{
			printf(" %s ********* ", line);
			line = get_next_line(fd);
	}
	// if (close(fd) != 0)
	// {
		// printf("Error closing file\n");
		// return (-1);
	// }
	return (0);
}

void free_ptr(char **ptr)
{
	if (*ptr != NULL && ptr != NULL)
	{
		free(ptr);
		*ptr = NULL;
	}
}

// return dub of the str with length n and allocate memory(malloc)
char	*ft_strndup(const char *str, size_t n)
{
	char	*result;

	if (!str)
		return (NULL);
	result = (cha *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, n + 1);
	return (result);
}
// returns
char	*join_line(int start, char **buffer_holder)
{
	char	*result;
	char	*temp;

	if (start <= 0)
	{
		if (**buffer_holder == '\0')
		{
			free_ptr((char **)buffer_holder);
			return (NULL);
		}
		result = ft_strndup(*buffer_holder, ft_strlen(*buffer_holder));
		free(*buffer_holder);
		*buffer_holder = NULL;
		return (result);
	}

	temp = ft_substr(*buffer_holder, start, BUFFER_SIZE);// (after start) substr of buff_holder with len BUFFER_SIZE
	result = ft_strndup(*buffer_holder, start); //(b4 start susbstr)substr of buffer_holder with len start
	free(*buffer_holder);
	if (!result)
	{
		free(temp);
		temp = NULL;
	}
	*buffer_holder = temp; // change buff_h: keep only substr from start, len BUFFER_SIZE and return substr beginning of buff_h
	// with length start
	return (result);
}

char	*read_line(int	fd, char **buffer_holder, char *curr_buffer)
{
	ssize_t bytes_read;
	char	*temp;
	char	*nl;

	// strchr return substr from the '\n' till the end of the str
	nl = ft_strchr(*buffer_holder, '\n');
	while (nl == NULL)
	{
		bytes_read = read(fd, curr_buffer, BUFFER_SIZE);
		if(bytes_read == -1)
		{
			free_ptr(*buffer_holder);
			return (NULL);
		}
		else if (bytes_read <= 0 && buffer_holder) // end of text
			return (join_line(bytes_read, buffer_holder));
		curr_buffer[bytes_read] = 0;
		temp = ft_str_join(*buffer_holder, curr_buffer);
		free_ptr(buffer_holder);
		if (!temp)
			return (NULL);
		buffer_holder = temp;
		if (*buffer_holder)
			nl = ft_strchr(*buffer_holder, '\n');
	}
	return (join_line(nl - *buffer_holder + 1, buffer_holder));
}