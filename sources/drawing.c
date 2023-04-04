/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:23:10 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/04 14:48:16 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

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
	while (sl->map[y])
	{
		while (sl->map[y][x])
		{
			mlx_image_to_window(sl->mlx, imgsol, (x * 64), (y * 64));
			if (sl->map[y][x] == '1')
				mlx_image_to_window(sl->mlx, img, (x * 64), (y * 64));
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

	map = sl->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				mlx_image_to_window(sl->mlx, sl->player, (x * 64), (y * 64));
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(sl->mlx, sl->player, (x * 64), (y * 64));
}
