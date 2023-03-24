/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:27:55 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/24 12:31:04 by ljerinec         ###   ########.fr       */
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
