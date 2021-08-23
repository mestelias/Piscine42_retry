/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:18:10 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/18 15:21:43 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_fonction(char *tab, int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			tab[k] = strs[i][j++];
			k++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			tab[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	tab[k] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			k++;
		}
		j = 0;
		while (sep[j])
		{
			j++;
			k++;
		}
		i++;
	}
	tab = malloc(sizeof(char) * (k + 1));
	return (ft_fonction(tab, size, strs, sep));
}
