#include <stdbool.h>
#include <unistd.h>

bool is_dub(char *str, char c, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

void inter(char *str1, char *str2)
{
	//check if doubles in str1 and str2 and then find common chars and print them
	int	i;
	int	j;

	i = 0;
	while (str1[i])
	{
		if (!is_dub(str1, str1[i], i))
		{
			if (str2[i] && !is_dub(str2, str2[i], i))
			{
				j = 0;
				while (str2[j])
				{
					if (str1[i] == str2[j])
					{
						write(1, &str1[i], 1);
					}
					j++;
				}
			}
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
reference: https://github.com/Glagan/42-exam-rank-02/blob/master/inter/subject.en.txt
*/