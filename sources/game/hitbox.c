/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:36:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:02 by ljerinec         ###   ########.fr       */
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
				if (player_x < (x * T_S + T_S)
					&& (player_x + sl->player->width) > (x * T_S)
					&& player_y < (y * T_S + T_S)
					&& (player_y + sl->player->height) > y * T_S)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	check_hitbox_c(t_solong *sl)
{
	int			i;
	int			nb_c;
	int			player_x;
	int			player_y;

	if (sl->game_on)
	{
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
				collect(sl, i);
			}
			i++;
		}
	}
}

void	collect(t_solong *sl, int i)
{
	mlx_image_t	*img;

	if (sl->collectible[i]->type == 'W')
	{
		sl->player->is_armed = 1;
		change_direction(sl, sl->player->direction);
		mlx_delete_image(sl->mlx, sl->collectible[i]->img);
	}
	else if (sl->collectible[i]->type == 'C'
		&& sl->collectible[i]->is_collected == 0)
	{
		sl->player->nb_collec++;
		sl->collectible[i]->is_collected = 1;
		mlx_delete_image(sl->mlx, sl->collectible[i]->img);
	}
	else if (sl->collectible[i]->type == 'E'
		&& sl->collectible[i]->is_collected == 0)
	{
		sl->collectible[i]->is_collected = 1;
		sl->game_on = 0;
		mlx_delete_image(sl->mlx, sl->player->img);
		img = mlx_put_string(sl->mlx, "You WIN !", sl->map->width_px / 2 - 200, sl->map->height_px / 2 - 40);
		mlx_resize_image(img, 400, 80);
	}
}

int	check_hitbox_shot(t_solong *sl, int sx, int sy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (sl->shot == NULL)
		return (0);
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

int	check_ennemy(t_solong *sl, int sx, int sy, int is_shot)
{
	int	i;

	i = 0;
	if (sl->ennemy == NULL)
		return (0);
	while (sl->ennemy[i])
	{
		if (sx < (sl->ennemy[i]->x + sl->ennemy[i]->width)
			&& (sx + 15) > sl->ennemy[i]->x
			&& sy < (sl->ennemy[i]->y + sl->ennemy[i]->height)
			&& (sy + 15) > sl->ennemy[i]->y
			&& sl->ennemy[i]->is_on)
		{
			if (is_shot)
			{
				sl->ennemy[i]->health -= 26;
				if (sl->ennemy[i]->health <= 0)
					sl->ennemy[i]->is_on = 0;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_player(t_solong *sl, int sx, int sy, int is_shot)
{
	sl->player->x = sl->player->img->instances[0].x;
	sl->player->y = sl->player->img->instances[0].y;
	if (sx < (sl->player->x + sl->player->width)
		&& (sx + 15) > sl->player->x
		&& sy < (sl->player->y + sl->player->height)
		&& (sy + 15) > sl->player->y)
	{
		if (is_shot)
		{
			sl->player->health -= 110;
			ft_printf("Player health : %d\n", sl->player->health);
		}
		return (1);
	}
	return (0);
}
