/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 15:49:26 by arommers      #+#    #+#                 */
/*   Updated: 2023/03/08 15:59:14 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

char *ft_strdup(char *str)
{
	int i;
	int len;
	char *dup;

	len = ft_strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	int 	i = 0;
	int 	br;
	char 	buffer;
	char	str[1000000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	br = read(fd, &buffer, 1);
	while (br > 0)
	{
		str[i++] = buffer;
		if (buffer = '\n')
			break ;
		br = read(fd, &buffer, 1);
	}
	str[i] = '\0';
	if (br == 0 && i == 0)	
		return (NULL);
	return (ft_strdup(str));
}
