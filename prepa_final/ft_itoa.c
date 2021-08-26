#include <unistd.h>
#include <stdlib.h>

void	convert(char *str, int nbr, int i)
{
	i--;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = nbr;
	if (nbr == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (nbr < 0)
		str[0] = '-';
	str[i] = '\0';
	convert(str, nbr, i);
	return (str);
}
