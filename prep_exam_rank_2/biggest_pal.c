#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void print_pal(char *str, int start, int end)
{
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
	write(1, "\n", 1);
}

bool	is_pal(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (false);
		start++;
		end--;
	}
	return (true); // true->is pal
}

void	biggest_pal(char *str)
{
	int strlen = ft_strlen(str);
	int max_len = 1, start = 0;
	int i = 0;
	int j;
	while (i < strlen)
	{
		j = i;
		while (j < strlen)
		{
			if (is_pal(str, i, j) && j - i + 1 > max_len)
			{
				start = i;
				max_len = j - i + 1;
			}
			j++;
		}
		i++;
	}
	print_pal(str, start, start + max_len - 1);
}

int	main (int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	biggest_pal(argv[1]);
	return (0);
}

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