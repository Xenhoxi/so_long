/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:12:29 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/11 15:50:34 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	count_c(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_c(map[y][x]) > 0)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

t_collect	*init_c(t_solong *sl, int x, int y, char type)
{
	t_collect	*collectible;

	collectible = malloc(sizeof(t_collect));
	if (type == 'C')
		collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[10]);
	if (type == 'W')
		collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[11]);
	collectible->x = x * T_S;
	collectible->y = y * T_S;
	collectible->type = type;
	collectible->is_collected = 0;
	collectible->current_img = 0;
	return (collectible);
}

void	create_c(t_solong *sl)
{
	char	**map;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	x = 0;
	map = sl->map->map;
	sl->collectible = malloc(sizeof(t_collect *) * count_c(sl->map->map));
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_c(map[y][x]) > 0)
			{
				sl->collectible[i] = init_c(sl, x, y, is_c(map[y][x]));
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

char	is_c(char type)
{
	if (type == 'C' || type == 'W')
		return (type);
	else
		return (-1);
}

void	draw_c(t_solong *sl)
{
	int	i;
	int	count;

	i = 0;
	count = count_c(sl->map->map);
	while (i < count)
	{
		if (sl->collectible[i]->is_collected == 0)
			mlx_image_to_window(sl->mlx, sl->collectible[i]->img,
				sl->collectible[i]->x, sl->collectible[i]->y);
		i++;
	}
}
