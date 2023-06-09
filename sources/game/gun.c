/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:57:14 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/21 00:48:57 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	shot(void *param)
{
	t_solong	*sl;
	int			x;
	int			y;

	sl = (t_solong *)param;
	if (sl->game_on)
	{
		x = sl->player->img->instances[0].x;
		y = sl->player->img->instances[0].y;
		if (mlx_is_key_down(sl->mlx, MLX_KEY_SPACE) && sl->player->is_armed
			&& sl->player->timer <= 0 && sl->player->health > 0)
		{
			shot_a_shot(sl, x, y, sl->player->direction);
			sl->player->timer = 1;
		}
		if (!mlx_is_key_down(sl->mlx, MLX_KEY_SPACE) && sl->player->timer >= 0)
			sl->player->timer--;
		move_shot(sl);
		check_shot_validity(sl);
	}
}

void	shot_a_shot(t_solong *sl, int _x, int _y, char dir)
{
	t_shot	*new_shot;

	new_shot = create_shot(sl, _x, _y, dir);
	sl->shot = array_join_shot(sl->shot, new_shot);
	place_shot(sl, new_shot);
}

void	place_shot(t_solong *sl, t_shot *shot)
{
	if (shot->direction == 'W')
	{
		shot->x += 24;
		shot->y -= 15;
	}
	else if (shot->direction == 'S')
	{
		shot->x += 4;
		shot->y += 50;
	}
	else if (shot->direction == 'D')
	{
		shot->x += 45;
		shot->y += 23;
	}
	else if (shot->direction == 'A')
	{
		shot->x -= 15;
		shot->y += 4;
	}
	mlx_image_to_window(sl->mlx, shot->img, shot->x, shot->y);
}

void	check_shot_validity(t_solong *sl)
{
	int	i;

	i = 0;
	if (sl->shot)
	{
		while (sl->shot[i])
		{
			if (sl->shot[i]->is_on)
			{
				if (sl->shot[i]->x < 0
					|| sl->shot[i]->x > sl->map->width_px
					|| sl->shot[i]->y < 0
					|| sl->shot[i]->y > sl->map->height_px
					|| check_hitbox_shot(sl, sl->shot[i]->x, sl->shot[i]->y)
					|| check_ennemy(sl, sl->shot[i]->x, sl->shot[i]->y, 1)
					|| check_player(sl, sl->shot[i]->x, sl->shot[i]->y, 1))
				{
					sl->shot[i]->is_on = 0;
					mlx_delete_image(sl->mlx, sl->shot[i]->img);
				}
			}
			i++;
		}
	}
}

void	move_shot(t_solong *sl)
{
	int	i;

	i = 0;
	if (sl->shot)
	{
		while (sl->shot[i])
		{
			if (sl->shot[i]->is_on)
			{
				if (sl->shot[i]->direction == 'W')
					sl->shot[i]->y -= (1000 * sl->dt);
				if (sl->shot[i]->direction == 'S')
					sl->shot[i]->y += (1000 * sl->dt);
				if (sl->shot[i]->direction == 'D')
					sl->shot[i]->x += (1000 * sl->dt);
				if (sl->shot[i]->direction == 'A')
					sl->shot[i]->x -= (1000 * sl->dt);
				sl->shot[i]->img->instances[0].x = sl->shot[i]->x;
				sl->shot[i]->img->instances[0].y = sl->shot[i]->y;
			}
			i++;
		}
	}
}
