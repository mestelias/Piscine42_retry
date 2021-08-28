/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:39:01 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/07 14:40:09 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_get_cnum(int x, int y, int a, int b)
{
	int		cnum;

	if ((a == 1 || a == y) && (b == 1 || b == x))
		cnum = 0;
	else if (a == 1 || a == y)
		cnum = 2;
	else if (b == 1 || b == x)
		cnum = 1;
	else
		cnum = 3;
	return (cnum);
}

void	rush(int x, int y)
{
	char	str[4];
	int		a;
	int		b;
	int		cnum;

	str[0] = 'o';
	str[1] = '|';
	str[2] = '-';
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
