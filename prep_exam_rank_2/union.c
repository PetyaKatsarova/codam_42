/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 11:25:12 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/03/23 15:26:46 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
*/

// # include <stdio.h>
#include <stdbool.h>

bool	is_dub(char *str, char c, int index)
{
	int	i = 0;
	
	while (i < index)
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);	
}

void	ft_union(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (str1[i])
		i++;
	while (str2[j])
	{
		str1[i++] = str2[j++];
	}
	while (k < i)
	{
		//write(1, &str1[k], 1);
		if (is_dub(str1, str1[k], k) == false)
			write(1, &str1[k], 1);
		k++;
	}
}
int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

// int ft_strchar(char *str, char c, int index)
// {
// 	int	count;

// 	count = 0;
// 	while (count < index)
// 	{
// 		if (str[count] == c)
// 			return (1);
// 		count++;
// 	}
// 	return (0);
// }

// void str_union(char *str1, char *str2)
// {
// 	int	i, str1_len;

// 	i = 0;
// 	while (str1[i])
// 	{
// 		if (ft_strchar(str1, str1[i], i) == 0)
// 		{
// 			write(1, &str1[i], 1);
// 		}
// 		i++;
// 	}
// 	str1_len = i;
// 	i = 0;
// 	while (str2[i])
// 	{
// 		if (ft_strchar(str1, str2[i], str1_len) == 0 && ft_strchar(str2, str2[i], i) == 0)
// 		{
// 			write(1, &str2[i], 1);
// 		}
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		str_union(argv[1], argv[2]);

// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

