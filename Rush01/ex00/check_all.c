/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:52:49 by nle-bret          #+#    #+#             */
/*   Updated: 2021/08/15 18:33:55 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_doubles(int map[MAP_SIZE][MAP_SIZE], int size, int pos[2])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < size)
	{
		if (x != pos[0] && map[pos[1]][x] == map[pos[1]][pos[0]])
			return (1);
		x++;
	}
	while (y < size)
	{
		if (y != pos[1] && map[y][pos[0]] == map[pos[1]][pos[0]])
			return (1);
		y++;
	}
	return (0);
}

int	check_up_views(int map[4][4], int views[4][4], int size, int pos[2])
{
	int		i;
	int		y;
	int		max;

	max = 0;
	y = 0;
	i = 0;
	while (y < size)
	{
		if (max < map[y][pos[0]])
		{
			max = map[y][pos[0]];
			i++;
		}
		y++;
	}
	if (i > views[UP][pos[0]])
		return (1);
	return (0);
}

int	check_down_views(int map[4][4], int views[4][4], int size, int pos[2])
{
	int		i;
	int		y;
	int		max;

	max = 0;
	y = size - 1;
	i = 0;
	while (y >= 0)
	{
		if (max < map[y][pos[0]])
		{
			max = map[y][pos[0]];
			i++;
		}
		y--;
	}
	if (map[MAP_SIZE - 1][pos[0]] != 0 && i > views[DOWN][pos[0]])
		return (1);
	return (0);
}

int	check_left_views(int map[4][4], int views[4][4], int size, int pos[2])
{
	int		i;
	int		x;
	int		max;

	max = 0;
	x = 0;
	i = 0;
	while (x < size)
	{
		if (max < map[pos[1]][x])
		{
			max = map[pos[1]][x];
			i++;
		}
		x++;
	}
	if (i > views[LEFT][pos[1]])
		return (1);
	return (0);
}

int	check_right_views(int map[4][4], int views[4][4], int size, int pos[2])
{
	int		i;
	int		max;
	int		x;

	x = size - 1;
	i = 0;
	max = 0;
	while (x >= 0)
	{
		if (max < map[pos[1]][x])
		{
			max = map[pos[1]][x];
			i++;
		}
		x--;
	}
	if (map[pos[1]][MAP_SIZE - 1] != 0 && i > views[RIGHT][pos[1]])
		return (1);
	return (0);
}
