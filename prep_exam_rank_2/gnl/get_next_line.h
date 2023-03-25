/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/25 14:55:45 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/03/25 18:39:08 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//The mos commonly used functions in <fcntl.h> include open(),
// close(), and fcntl().

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_substr(char const *s, int start, int len);
#endif
