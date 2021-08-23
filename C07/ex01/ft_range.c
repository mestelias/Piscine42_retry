/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:11:27 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/08 12:40:33 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	int		count;

	count = 0;
	if (min >= max)
		return (0);
	tab = malloc(sizeof(int) * (max - min + 1));
	if (tab == 0)
		return (0);
	while (min < max)
	{
		tab[count] = min;
		min++;
		count++;
	}
	tab[count] = '\0';
	return (tab);
}
