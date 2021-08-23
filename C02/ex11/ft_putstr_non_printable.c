/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:23:40 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/11 14:11:12 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexadecimal(unsigned char c)
{
	unsigned char	nb;
	char			*base_hexa;
	int				a;
	int				b;

	nb = c;
	base_hexa = "0123456789abcdef";
	a = (nb / 16) % 16;
	b = nb % 16;
	ft_putchar('\\');
	ft_putchar(base_hexa[a]);
	ft_putchar(base_hexa[b]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			ft_hexadecimal(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
