/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:45:34 by nle-bret          #+#    #+#             */
/*   Updated: 2021/08/15 20:09:47 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_map(int tab[MAP_SIZE][MAP_SIZE])
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			ft_putchar(tab[y][x] + '0');
			if (x < MAP_SIZE - 1)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int	filter_input(char *arg, char *input)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (is_digit(arg[i]))
		{
			if (j >= MAP_SIZE * 4 || arg[i] < '1' || arg[i] > MAP_SIZE + '0')
				return (1);
			input[j] = arg[i];
			j++;
		}
		else if (is_separator(arg[i]) == 0)
			return (1);
		i++;
	}
	input[j] = '\0';
	if (j % 4 != 0)
		return (1);
	return (0);
}

void	make_views(char *input, int	views[MAP_SIZE][MAP_SIZE])
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			views[y][x] = input[i] - '0';
			i++;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	int		map[MAP_SIZE][MAP_SIZE];
	char	input[(MAP_SIZE * 4) + 1];
	int		views[4][MAP_SIZE];
	int		pos[2];

	if (argc != 2)
		return (ft_print_error());
	if (filter_input(argv[1], input))
		return (ft_print_error());
	make_views(input, views);
	pos[0] = 0;
	pos[1] = 0;
	initialize_map(map, MAP_SIZE);
	if (solve_map(map, views, MAP_SIZE, pos) == 0)
		return (ft_print_error());
	else
		print_map(map);
	return (0);
}
