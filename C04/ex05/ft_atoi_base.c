/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:35:13 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/20 10:33:36 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int		nb;

	nb = 0;
	while (*(str++))
		nb++;
	return (nb);
}

int	check_char(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		atoi;
	int		len;

	i = 0;
	j = 1;
	atoi = 0;
	len = ft_strlen(base);
	if (check_base(base) != 1)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			j = -j;
	while (check_char(str[i], base) != -1)
		atoi = atoi * len + (check_char(str[i++], base));
	return (atoi * j);
}
