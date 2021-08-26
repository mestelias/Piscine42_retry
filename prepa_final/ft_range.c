#include <unistd.h>
#include <stdlib.h>


int		ft_abs(int	x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int     *ft_range(int start, int end)
{
	int		i;

	i = 0;
	tab = malloc(sizeof(int) * ft_abs(start - end) + 1);
	if (tab == NULL)
		return (NULL);
	while (start < end)
	{
		tab[i] = start;
		start++;
		i++;
	}
	tab[i] = start;
	while (start > end)
	{
		tab[i] = start;
		start--;
		i++;
	}
	tab[i] = start;
	return (tab);
}
