
#include <stdio.h>
#include <stdlib.h>

int	check_anagram(char *str1, char *str2)
{
	int	i = 0;
	int	j = 0;
	int	count[128] = {0};

	while (str1[i])
		count[str1[i++]]++;
	i = 0;
	while (str2[i])
		count[str2[i++]]--;
	while (j < 128)
	{
		if (count[j] != 0)
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
