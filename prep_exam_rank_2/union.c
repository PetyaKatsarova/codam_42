# include <unistd.h>

int	verify_char(int index, char *str, char c)
{
	int	i;

	i = 0; 
	while (i < index)
	{
		if (str[i] == c && c != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	str_union(char *str1, char *str2)
{
	int	i, str1_len;

	i = 0;
	while (str1[i])
	{
		if (verify_char(i, str1, str1[i]) == 0)
			write(1, &str1[i], 1);
		i++;
	}
	str1_len = i;
	i = 0;
	while (str2[i])
	{
		if (verify_char(str1_len, str1, str2[i]) == 0)
		{
			if (verify_char(i, str2, str2[i]) == 0)
				write(1, &str2[i], 1);
		}
		i++;
	}
}

int main(int argc, char	**argv)
{
	if (argc != 3)
	{
		write(1, "Did you put 2 strings?", 22);
		return (-1);
	}
	str_union(argv[1], argv[2]);
	return (0);
}

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