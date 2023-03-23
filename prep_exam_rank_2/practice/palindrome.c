
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str);
int	check_pala(char *str, int start, int end);

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	check_pala(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j;
	int	len = ft_strlen(argv[1]);
	int	start = 0;
	int	end = 0;
	int	max_len = 0;

	if (argc == 2)
	{
		while (i < len)
		{
			j = i + max_len;
			while (j < len && j < i + len - max_len)
			{
				if (check_pala(argv[1], i, j) == 1)
				{
					max_len = j - i + 1;
					start = i;
				}
				j++;
			}
			i++;
		}
		if (max_len > 0)
		{
			i = start -1;
			end = start + max_len;
			while (i <= end)
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
		write (1, "\n", 1);
		return (0);
	}
}
