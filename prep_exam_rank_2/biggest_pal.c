/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_pal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 11:24:53 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/03/23 14:56:09 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/*
Assignment name  : biggest_pal
Expected files   : *.c, *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named biggest_pal that takes a string as argument and prints the
biggest palindrome included inside this string, followed by a newline.

This string contains only lowercase characters.

If there are two palindromes of the same length, you have to print the last one.

If there is more or less than 1 argument, your program must print only a newline
only. ✓

Exemples:

$> biggest_pal "abcba"
abcba
$> biggest_pal "aaaaaaaaaabbcbbaaaa"
aaaabbcbbaaaa
$> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
zeldaisaboyobasiadlez
$> biggest_pal "aeibaabaammaabaalek"
aabaammaabaa
$> biggest_pal abeb qpinqwjobo qkmnwoiq
$> biggest_pal
A palindrome is a word, phrase, number, or other sequence of characters that reads the
same forward and backward. racecar
$>

*/

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

bool is_pal(char *str, int start, int end)
{
	while (start <= end)
	{
		if (str[start++] != str[end--])
			return (false);
	}
	return (true);
}

void print_it(char *str, int start, int end)
{
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

void biggest_pal(char *str)
{
	int i = 0;
	int	j = 0, biggest = 1, start;

	while (str[i])
	{
		j = i;
		while (j < ft_strlen(str))
		{
			if (is_pal(str, i, j) && biggest <= j - i + 1)
			{
				start = i;
				biggest = j - i + 1;
			}
			j++;
		}
		i++;	
	}
	print_it(str, start, biggest + start - 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}