/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:40:50 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/07 15:18:20 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_get_cnum(int x, int y, int a, int b)
{
	int		cnum;

	if (a == 1 && b == 1)
		cnum = 0;
	else if ((a == 1 && b == x) || (a == y && b == 1))
		cnum = 2;
	else if (a == y && b == x)
		cnum = 0;
	else if ((a != 1 && a != y) && (b != 1 && b != x))
		cnum = 3;
	else
		cnum = 1;
	return (cnum);
}

void	rush(int x, int y)
{
	char	str[4];
	int		a;
	int		b;
	int		cnum;

	str[0] = '/';
	str[1] = '*';
	str[2] = '\\';
	str[3] = ' ';
	a = 1;
	cnum = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (a < y)
	{
		b = 1;
		while (b < x)
		{
			cnum = ft_get_cnum(x, y, a, b);
			ft_putchar(str[cnum]);
			b++;
		}
		ft_putchar('\n');
		a++;
	}
}
