/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/25 14:57:23 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/03/25 18:40:11 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_join(char const *str1, char const *str2)
{
	int 	i;
	char	*result;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	result = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (*str1)
		result[i++] = *str1++;
	while (*str2)
		result[i++] = *str2++;
	result[i] = 0;
	return (result);
}

char	*ft_substr(char const *str, int start, int len)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (str[start] && i < len)
	{
		result[i++] = str[start++];
	}
	result[i] = 0;
	return (result);
}

size_t ft_strlcpy(char *dst, const char *src, int dstsize)
{
	size_t	i;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (i < (src_len - 1) && src[i])
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	if (!s)
		return (NULL);
	result = (char *)s;
	while (*result != (char)c)
	{
		if (!*result)
			return (0);
		result++;
	}
	return (result);
}

// int main(void)
// {
// 	char *str = ft_strchr("Hello World", 'W');
// 	printf("%s\n", str);
	
// 	return (0);
// }


// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		char	*result;

// 		//result = ft_substr((int)argv[1], (int)argv[2], (int)argv[3]);
// 		result = ft_substr(argv[3], atoi(argv[1]), atoi(argv[2]));
// 		printf("start: %s, len: %s, from [%s]: substr: ** %s **\n", argv[1], argv[2], argv[3], result);
	
// 	}
// 	return (0);
// }