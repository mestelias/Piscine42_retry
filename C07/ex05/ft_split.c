/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:35:56 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/22 20:07:53 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_nb_line(char *str, char *charset)
{
	int		i;
	int		nb;
	char	**result;

	nb = !is_charset(str[0], charset);
	i = 1;
	while (str[i])
	{
		if (is_charset(str[i - 1], charset) && !is_charset(str[i], charset))
			nb++;
		i++;
	}
	result = malloc(sizeof (char *) * (nb + 1));
	if (!result)
		return (NULL);
	result[nb] = NULL;
	return (result);
}

char	*ft_strdup(char *src, char *charset)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (src[i] && !is_charset(src[i], charset))
	{
		len++;
		i++;
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	i = 0;
	while (src[i] && !is_charset(src[i], charset))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		cpt;

	cpt = 0;
	i = 0;
	result = ft_nb_line(str, charset);
	if (!result)
		return (0);
	while (str[i])
	{
		while (is_charset(str[i], charset))
			i++;
		if (str[i])
		{
			result[cpt] = ft_strdup(str + i, charset);
			if (!result[cpt])
				return (0);
			cpt++;
		}
		while (!is_charset(str[i], charset) && str[i])
			i++;
	}
	return (result);
}
/*
   int		main(int ac, char **av)
   {
   int	i;
   char **tab;
   (void)ac;

   i = -1;
   tab = malloc(sizeof(*tab) * (ft_nb_strings(av[1], av[2]) + 1));
   tab = ft_split(av[1], av[2]);
   while (++i < ft_nb_strings(av[1], av[2]) + 1)
   printf("tab[%i]\t=\t\t%s\n", i, tab[i]);
   return (0);
}*/
