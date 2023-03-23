
#include <stdio.h>
#include <stdlib.h>

int	check_ana(char *str1, char *str2)
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

int	main(void)
{
	char	*str1 = "";
	char	*str2 = "";

	if (check_ana(str1, str2) == 1)
		printf("these strings are not anagrams\n");
	else
		printf("these strings are anagrams\n");
}
