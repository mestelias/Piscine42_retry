/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:49:29 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/17 18:55:10 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_check_char(char c, char *base);
int	ft_strlen(char *str);
int	ft_isspace(char c);

int	ft_check_base(char *base)
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
		if (ft_isspace(base[i]))
			return (0);
		if (base[i] == '+' || base[i] == '-')
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

int	ft_getsize(int nb, char *base)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / ft_strlen(base);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nb, char *str, char *base, int *index)
{
	int		size;

	size = ft_strlen(base);
	if (nb == -2147483648)
	{
		str[0] = '-';
		(*index)++;
		ft_putnbr_base((-(long int)nb) / size, str, base, index);
		ft_putnbr_base((-(long int)nb) % size, str, base, index);
	}
	else if (nb < 0)
	{
		str[0] = '-';
		(*index)++;
		ft_putnbr_base(-nb, str, base, index);
	}
	else if (nb < size)
		str[(*index)++] = base[nb];
	else
	{
		ft_putnbr_base(nb / size, str, base, index);
		ft_putnbr_base((nb) % size, str, base, index);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		nb;
	int		index;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	str = NULL;
	str = malloc(sizeof(char) * (ft_getsize(nb, base_to) + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	ft_putnbr_base(nb, str, base_to, &index);
	str[ft_getsize(nb, base_to)] = '\0';
	return (str);
}
