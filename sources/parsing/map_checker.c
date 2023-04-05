/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:27:55 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/05 13:25:27 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	checking(t_solong *solong)
{
	char	**map;

	map = solong->map;
	if (map_checking(map) == 0)
		printf("Error\n");
	else
	{
		print_char_map(map);
		solong->map_width = ft_strlen_gnl(map[0]);
		solong->map_height = array_len(map);
		solong->tile_heigth = solong->map_height * T_S;
		solong->tile_width = solong->map_width * T_S;
	}
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

int	map_is_rectangle(char **map)
{
	int	i;
	int	height;
	int	width;

	height = array_len(map);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen_gnl(map[i]) != width)
			return (0);
		i++;
	}
	if (width < height)
		return (0);
	return (1);
}

int	player_spawn(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
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

int	map_is_closed(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	j = 0;
	height = array_len(map);
	width = ft_strlen(map[0]);
	while (map[i])
	{
		while (map[i][j])
		{
			if (i == 0 || i == height - 1)
				if (map[i][j] != '1')
					return (0);
			if (j == 0 || j == width - 1)
				if (map[i][j] != '1')
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
