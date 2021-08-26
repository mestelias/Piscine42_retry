#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	op;
	int		res;

	res = 0;
	if (argc == 4)
	{
		i = atoi(argv[1]);
		op = argv[2][0];
		j = atoi(argv[3]);
		if (op == '+')
			res = i + j;
		else if (op == '-')
			res = i - j;
		else if (op == '*')
			res = i * j;
		else if (op == '/')
			res = i / j;
		else if (op == '%')
			res = i % j;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}
