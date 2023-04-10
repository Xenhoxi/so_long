/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:39:06 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/07 15:05:25 by ljerinec         ###   ########.fr       */
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

void	change_direction(t_solong *sl, char direction)
{
	int				x;
	int				y;

	y = sl->player->img->instances[0].y;
	x = sl->player->img->instances[0].x;
	sl->player->direction = direction;
	if (direction == 'W')
		change_img(sl, x, y, 0);
	if (direction == 'S')
		change_img(sl, x, y, 1);
	if (direction == 'A')
		change_img(sl, x, y, 2);
	if (direction == 'D')
		change_img(sl, x, y, 3);
}

void	change_img(t_solong *sl, int x, int y, int i)
{
	mlx_delete_image(sl->mlx, sl->player->img);
	if (sl->player->is_armed == 0)
		sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[i]);
	else if (sl->player->is_armed == 1)
		sl->player->img = mlx_texture_to_image(sl->mlx, sl->texture[i + 4]);
	mlx_image_to_window(sl->mlx, sl->player->img, x, y);
}
