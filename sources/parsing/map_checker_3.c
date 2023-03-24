/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:27:57 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/24 14:13:39 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	check_all(char **map, int **int_map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				if (int_map[x][y] == 0)
					return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int	check_side(int **int_map, int x, int y)
{
	int	count;

	count = 0;
	if (int_map[x][y + 1] == 0)
	{
		count++;
		int_map[x][y + 1] = int_map[x][y] + 1;
	}
	if (int_map[x][y - 1] == 0)
	{
		count++;
		int_map[x][y - 1] = int_map[x][y] + 1;
	}
	if (int_map[x + 1][y] == 0)
	{
		count++;
		int_map[x + 1][y] = int_map[x][y] + 1;
	}
	if (int_map[x - 1][y] == 0)
	{
		count++;
		int_map[x - 1][y] = int_map[x][y] + 1;
	}
	return (count);
}

int	find_coord(char **map, int **int_map, int i)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (int_map[x][y] == i)
				count += check_side(int_map, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	return (count);
}

int	**map_in_int(char **map)
{
	int	**int_map;
	int	x;
	int	y;

	x = 0;
	y = 0;
	int_map = malloc(sizeof(int *) * array_len(map));
	while (map[x])
	{
		int_map[x] = malloc(sizeof(int) * ft_strlen(map[x]));
		while (map[x][y])
		{
			if (map[x][y] == '1')
				int_map[x][y] = 1;
			else
			int_map[x][y] = 0;
			y++;
		}
		y = 0;
		x++;
	}
	return (int_map);
}
