/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:36:30 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/24 16:36:40 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write(int n, int tab[], int add)
{
	int	i;

	i = 0;
	if (add == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_incr(int n, int tab[])
{
	int	i;
	int	max;

	max = 9;
	i = n - 1;
	while (tab[i] == max)
	{
		i--;
		max--;
	}
	tab[i]++;
	while (i < n)
	{
		tab[i + 1] = tab[i] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	ft_write(n, tab, 0);
	while ((tab[0] != 10 - n) || (tab[n - 1] != 9))
	{
		if (tab [n - 1] != 9)
			tab[n - 1]++;
		else
			ft_incr(n, tab);
		ft_write(n, tab, 1);
	}
}
/*
#include <libc.h>
int main(int ac, char **av)
{
	(void)ac;
	ft_print_combn(atoi(av[1]));
	return (0);
}
*/
