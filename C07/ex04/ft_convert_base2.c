/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:50:10 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/16 19:25:56 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_check_base(char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_size(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (i >= ft_strlen(base))
		return (-1);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!ft_check_base(base))
		return (0);
	size = ft_strlen(base);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_size(str[i], base) >= 0)
		res = res * size + ft_size(str[i++], base);
	return (sign * res);
}
