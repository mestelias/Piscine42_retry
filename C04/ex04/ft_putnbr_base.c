/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:11:56 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/09 13:55:56 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(char *str)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (str[i])
	{
		tmp = 0;
		j = 0;
		while (str[j])
		{
			if (str[i] == str[j])
				tmp++;
			if (tmp > 1)
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int		lenbase;
	long int		n;

	n = (long int) nbr;
	lenbase = ft_check(base);
	if (lenbase == 0)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= lenbase)
		ft_putnbr_base(n / lenbase, base);
	ft_putchar(base[n % lenbase]);
}
