/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:17:45 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/06 16:51:32 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	key_hook(t_solong *sl)
{
	mlx_t	*mlx;

	mlx = sl->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	vertical_move(t_solong *sl)
{
	mlx_t	*mlx;
	int		player_x;
	int		player_y;

	mlx = sl->mlx;
	player_x = sl->player->img->instances[0].x;
	player_y = sl->player->img->instances[0].y;
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, player_x, player_y - 2))
		{
			sl->player->img->instances[0].y -= 2;
			change_direction(sl, 'W');
			check_hitbox_c(sl, player_x, player_y - 2);
		}
	}
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, player_x, player_y + 2))
		{
			sl->player->img->instances[0].y += 2;
			change_direction(sl, 'S');
			check_hitbox_c(sl, player_x, player_y + 2);
		}
	}
}

void	horizontal_move(t_solong *sl)
{
	mlx_t	*mlx;
	int		player_x;
	int		player_y;

	mlx = sl->mlx;
	player_x = sl->player->img->instances[0].x;
	player_y = sl->player->img->instances[0].y;
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, player_x - 2, player_y))
		{
			sl->player->img->instances[0].x -= 2;
			change_direction(sl, 'A');
			check_hitbox_c(sl, player_x - 2, player_y);
		}
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, player_x + 2, player_y))
		{
			sl->player->img->instances[0].x += 2;
			change_direction(sl, 'D');
			check_hitbox_c(sl, player_x + 2, player_y);
		}
	}
}

void	change_direction(t_solong *sl, char c)
{
	int				x;
	int				y;

	y = sl->player->img->instances[0].y;
	x = sl->player->img->instances[0].x;
	if (c == 'W')
	{
		mlx_delete_image(sl->mlx, sl->player->img);
		sl->player->img = mlx_new_image(sl->mlx, sl->player->width, sl->player->height);
		sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[0]);
		mlx_image_to_window(sl->mlx, sl->player->img, x, y);
	}
	if (c == 'S')
	{
		mlx_delete_image(sl->mlx, sl->player->img);
		sl->player->img = mlx_new_image(sl->mlx, sl->player->width, sl->player->height);
		sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[1]);
		mlx_image_to_window(sl->mlx, sl->player->img, x, y);
	}
	if (c == 'A')
	{
		mlx_delete_image(sl->mlx, sl->player->img);
		sl->player->img = mlx_new_image(sl->mlx, sl->player->width, sl->player->height);
		sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[2]);
		mlx_image_to_window(sl->mlx, sl->player->img, x, y);
	}
	if (c == 'D')
	{
		mlx_delete_image(sl->mlx, sl->player->img);
		sl->player->img = mlx_new_image(sl->mlx, sl->player->width, sl->player->height);
		sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[3]);
		mlx_image_to_window(sl->mlx, sl->player->img, x, y);
	}
}
