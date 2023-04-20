/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:26:46 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/20 13:12:13 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

char	is_c(char type)
{
	if (type == 'C' || type == 'W' || type == 'E')
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
		if (sl->collectible[i]->is_collected == 0
			&& sl->collectible[i]->type != 'E')
			mlx_image_to_window(sl->mlx, sl->collectible[i]->img,
				sl->collectible[i]->x, sl->collectible[i]->y);
		i++;
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
		img = mlx_put_string(sl->mlx, "You WIN !",
				sl->map->width_px / 2 - 200, sl->map->height_px / 2 - 40);
		mlx_resize_image(img, 400, 80);
	}
}
