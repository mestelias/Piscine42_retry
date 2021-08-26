/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:20:16 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/08 15:35:58 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_get_cnum(int x, int y, int a, int b);
void	rush(int x, int y);
void	ft_putchar(char c);

int	main(void)
{
	rush(5, 3);
	write(1, "\n", 1);
	rush(5, 1);
	write(1, "\n", 1);
	rush(1, 1);
	write(1, "\n", 1);
	rush(1, 5);
	write(1, "\n", 1);
	rush(4, 4);
	return (0);
}
