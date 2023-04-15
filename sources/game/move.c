/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:17:45 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/15 17:18:38 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	move(t_solong *sl)
{
	mlx_t	*mlx;
	int		player_x;
	int		player_y;

	mlx = sl->mlx;
	player_x = sl->player->img->instances[0].x;
	player_y = sl->player->img->instances[0].y;
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
		check_left(sl, player_x, player_y);
	if (mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
		check_right(sl, player_x, player_y);
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
		check_up(sl, player_x, player_y);
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && mlx_is_key_down(mlx, MLX_KEY_S))
		check_down(sl, player_x, player_y);
}

void	check_up(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x, player_y - 2)
		&& !check_ennemy(sl, player_x, player_y - 2, 0))
	{
		sl->player->img->instances[0].y -= 2;
		sl->player->score += 2;
		change_direction(sl, 'W');
	}
}

void	check_down(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x, player_y + 2)
		&& !check_ennemy(sl, player_x, player_y + 2, 0))
	{
		sl->player->img->instances[0].y += 2;
		sl->player->score += 2;
		change_direction(sl, 'S');
	}
}

void	check_right(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x + 2, player_y)
		&& !check_ennemy(sl, player_x + 2, player_y, 0))
	{
		sl->player->img->instances[0].x += 2;
		sl->player->score += 2;
		change_direction(sl, 'D');
	}
}

void	check_left(t_solong *sl, int player_x, int player_y)
{
	if (!check_hitbox(sl, player_x - 2, player_y)
		&& !check_ennemy(sl, player_x - 2, player_y, 0))
	{
		sl->player->img->instances[0].x -= 2;
		sl->player->score += 2;
		change_direction(sl, 'A');
	}
}
