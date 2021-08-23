/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:38:39 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/18 16:50:00 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		*tab;
	int		i;
	int		len;

	len = max - min;
	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	tab = malloc(sizeof(*tab) * len);
	if (tab == NULL)
		return (-1);
	while (i < len)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (len);
}
