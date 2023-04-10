/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:36:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/11 01:43:57 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	check_hitbox(t_solong *sl, int player_x, int player_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (sl->map->map[y])
	{
		while (sl->map->map[y][x])
		{
			if (sl->map->map[y][x] == '1')
			{
				if (player_x < (x * 64) + T_S
					&& player_x + sl->player->width > x * 64
					&& player_y < y * 64 + T_S
					&& player_y + sl->player->height > y * 64)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	check_hitbox_c(void *param)
{
	int			i;
	int			nb_c;
	int			player_x;
	int			player_y;
	t_solong	*sl;

	sl = (t_solong *)param;
	player_x = sl->player->img->instances[0].x;
	player_y = sl->player->img->instances[0].y;
	nb_c = count_c(sl->map->map);
	i = 0;
	while (i < nb_c)
	{
		if (player_x < (sl->collectible[i]->x) + T_S
			&& player_x + sl->player->width > sl->collectible[i]->x
			&& player_y < sl->collectible[i]->y + T_S
			&& player_y + sl->player->height > sl->collectible[i]->y
			&& mlx_is_key_down(sl->mlx, MLX_KEY_E))
		{
			sl->collectible[i]->is_collected = 1;
			mlx_delete_image(sl->mlx, sl->collectible[i]->img);
			if (sl->collectible[i]->type == 'W')
			{
				sl->player->is_armed = 1;
				change_direction(sl, sl->player->direction);
			}
		}
		i++;
	}
}

int	check_hitbox_shot(t_solong *sl, int sx, int sy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (sl->map->map[y])
	{
		while (sl->map->map[y][x])
		{
			if (sl->map->map[y][x] == '1')
			{
				if (sx < (x * 64) + T_S
					&& sx + 15 > x * 64
					&& sy < y * 64 + T_S
					&& sy + 15 > y * 64)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
