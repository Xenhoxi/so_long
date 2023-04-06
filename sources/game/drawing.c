/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:23:10 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/06 16:45:59 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	draw(t_solong *sl)
{
	mlx_image_t	*img;
	mlx_image_t	*imgsol;
	int			x;
	int			y;

	imgsol = mlx_texture_to_image(sl->mlx, sl->texture[5]);
	img = mlx_texture_to_image(sl->mlx, sl->texture[4]);
	x = 0;
	y = 0;
	while (sl->map->map[y])
	{
		while (sl->map->map[y][x])
		{
			mlx_image_to_window(sl->mlx, imgsol, (x * T_S), (y * T_S));
			if (sl->map->map[y][x] == '1')
				mlx_image_to_window(sl->mlx, img, (x * T_S), (y * T_S));
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_player(t_solong *sl)
{
	char	**map;
	int		x;
	int		y;

	sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[3]);
	map = sl->map->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				mlx_image_to_window(sl->mlx, sl->player->img, x * T_S, y * T_S);
			x++;
		}
		x = 0;
		y++;
	}
}

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
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

t_collectible	*init_c(t_solong *sl, int x, int y)
{
	t_collectible	*collectible;

	collectible = malloc(sizeof(t_collectible));
	collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[6]);
	collectible->x = x * T_S;
	collectible->y = y * T_S;
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
	sl->collectible = malloc(sizeof(t_collectible *) * count_c(sl->map->map));
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				sl->collectible[i] = init_c(sl, x, y);
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_c(t_solong *sl)
{
	int	i;

	i = 0;
	while (i < count_c(sl->map->map))
	{
		if (sl->collectible[i]->is_collected == 0)
			mlx_image_to_window(sl->mlx, sl->collectible[i]->img,
				sl->collectible[i]->x, sl->collectible[i]->y);
		i++;
	}
}
