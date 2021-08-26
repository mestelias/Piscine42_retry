#include <unistd.h>

int main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (*argv[1])
			argv[1]++;
		argv[1]--;
		while ((*argv[1] >= 9 && *argv[1] <= 13) || *argv[1] == 32)
			argv[1]--;
		while (*argv[1] >= 33 && *argv[1] <= 126)
			argv[1]--;
		argv[1]++;
		while (*argv[1] >= 33 && *argv[1] <= 126)
			write(1, argv[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
