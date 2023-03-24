/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:27:55 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/24 01:29:57 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	checking(char **map)
{
	if (map_checking(map) == 0)
		printf("Error\n");
	else
		printf("OK\n");
}

int	map_checking(char **map)
{
	if (map_is_rectangle(map) == 1)
		if (player_spawn(map) == 1)
			if (map_is_closed(map) == 1)
				if (map_exit(map) == 1)
					if (map_collectible(map) == 1)
						if (coord_is_possible(map) == 1)
							return (1);
	return (0);
}

void	find_spawn(char **map, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (map[*x])
	{
		while (map[*x][*y])
		{
			if (map[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		*y = 0;
		(*x)++;
	}
}

void	check_side(char **map, int x, int y)
{
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

int	coord_is_possible(char **map)
{
	int	**int_map;
	int	x;
	int	y;

	int_map = map_in_int(map);
	find_spawn(map, &x, &y);
	int_map[x][y] = 2;
	y = 0;
	x = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			printf("%d", int_map[x][y]);
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
	find_spawn(map, &x, &y);
	return (1);
}
