#include <unistd.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int		i;
	int		*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
