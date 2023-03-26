/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:19:04 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/26 05:11:52 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	map_exit(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	map_collectible(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	coord_is_possible(char **map)
{
	int	**int_map;
	int	x;
	int	y;
	int	i;
	int	count;

	int_map = map_in_int(map);
	find_spawn(map, &x, &y);
	int_map[x][y] = 2;
	i = 2;
	count = 1;
	while (count >= 0)
	{
		count = find_coord(map, int_map, i++);
		count--;
	}
	if (check_all(map, int_map) == 0)
		return (0);
	free_int_map(int_map);
	return (1);
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

void	free_int_map(int **int_map)
{
	int	i;

	i = 0;
	while (int_map[i])
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
	int_map = 0;
}
