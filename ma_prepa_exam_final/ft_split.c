#include <unistd.h>
#include <stdlib.h>

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		count_word(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
		{
			count++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char 	*tab;
	int		i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char    **ft_split(char *str)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	array = malloc(sizeof(char *) * (count_word(str) + 1));
	if (array == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
		{
			array[j] = malloc_word(&str[i]);
			j++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	array[j] = NULL;
	return (array);
}

#include <stdio.h>

int		main(int ac, char **av)
{
 	char **arr;

 	char *phrase = "   Hello,   Flavio\t Wuensche!  ";
 	arr = ft_split(phrase);
 	printf("%s\n", arr[0]);
 	printf("%s\n", arr[1]);
 	printf("%s\n", arr[2]);
 	printf("%s\n", arr[3]);
}
