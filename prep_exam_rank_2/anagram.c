/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   anagram.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 13:14:37 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/03/23 14:10:56 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Returns whether the first string is an anagram of the second or not.
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	check_anagram(char *str1, char *str2)
{
	int	i = 0;
	int	j = 0;
	int	words[128] = {0};

	while (str1[i])
		words[str1[i++]]++;
	i = 0;
	while (str2[i])
		words[str2[i++]]--;
	while (j < 128)
	{
		//printf("%i -- ", words[str1[j]]);
		if (words[str1[j]] != 0)
			return (1);
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (check_anagram(argv[1], argv[2]) == 1)
			printf("these strings are not anagrams\n");
		else
			printf("these strings are anagrams\n");
	}
	return(0);
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
