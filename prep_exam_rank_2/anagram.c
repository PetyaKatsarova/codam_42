/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   anagram.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 13:14:37 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/03/22 13:46:05 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Returns whether the first string is an anagram of the second or not.
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

bool ft_strchr(char *str, char c)
{
	int i = 0;

	while (str[i])
	{
		if (str[i++] != c)
		{
			printf("%c ** ", str[i]);
			return (false);
		}
	}
	return (true);
}


void	is_anagram(char *str1, char *str2)
{
	int	j = 0;
	bool is_ana = true;

	while (str2[j])
	{
		if (ft_strchr(str1, str2[j]) == false)
		{
			printf("%c --\\", str2[j]);
			is_ana = false;
			break ;
		}
		j++;
	}
	if (is_ana)
		write(1, "is anagram", 10);
	else
		write(1, "not anagram", 11);
}

int	main(int argc, char **argv)
{
	
	if (argc == 3)
		is_anagram(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}


/*
ALERT: OPTIMIZED SOLUTION REQUIRED.
An anagram is a sequence of characters formed by rearranging the letters of
another sequence, such as 'cinema', formed from 'iceman'.
Given two strings as parameters, create a function able to tell whether or
not the first string is an anagram of the second.
The function must be declared as follows:
int is_anagram(char *a, char *b);
Considerations:
- Be careful: the naive solution won't work on our big input, you have to
find an optimized solution which will run in O(sa + sb) time (where sa is
the length of a and sb length of b).
- Our tested string will always be a sequence of ascii characters between 32
and 126 inclusive.
- The bigger test we will do is on 2 sequences of 1.000.000 characters each.
It should run in less than 2 seconds.
Example 1:
a='abcdef'
b='fabcde'
In this case, these two strings are anagrams, your function should return 1.
Example 2:
a='.123?.'
b='?321..'
In this case, these two strings are anagrams, your function should return 1.
Example 3:
a='abca'
b='bcab'
In this case, these two strings are not anagrams, your function should return 0.
*/