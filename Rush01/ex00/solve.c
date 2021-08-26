/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:15:24 by nle-bret          #+#    #+#             */
/*   Updated: 2021/08/15 20:07:07 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_map(int map[MAP_SIZE][MAP_SIZE], int size)
{
	int	x;
	int	y;
	int	i;
	int	tot_size;

	i = 0;
	tot_size = (size * size);
	while (i < tot_size)
	{
		x = i % size;
		y = i / size;
		map[y][x] = 0;
		i++;
	}
}

int	check(int map[4][4], int views[4][4], int size, int pos[2])
{
	if (check_doubles(map, size, pos))
		return (1);
	if (check_up_views(map, views, size, pos))
		return (1);
	if (check_down_views(map, views, size, pos))
		return (1);
	if (check_left_views(map, views, size, pos))
		return (1);
	if (check_right_views(map, views, size, pos))
		return (1);
	return (0);
}

int	solve_map(int map[4][4], int views[4][4], int size, int pos[2])
{
	int	i;

	i = 0;
	while (++i <= size)
	{
		map[pos[1]][pos[0]] = i;
		if (check(map, views, size, pos) == 0)
		{
			if (pos[0] < size - 1)
			{
				if (solve_map(map, views, size, (int [2]){pos[0] + 1, pos[1]}))
					return (1);
			}
			else if (pos[0] == size - 1 && pos[1] < size - 1)
			{
				if (solve_map(map, views, size, (int [2]){0, pos[1] + 1}))
					return (1);
			}
			else if (pos[0] == size - 1 && pos[1] == size - 1)
				return (1);
		}
	}
	map[pos[1]][pos[0]] = 0;
	return (0);
}
