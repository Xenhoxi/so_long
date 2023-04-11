/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:57:14 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/11 15:32:39 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	shot(void *param)
{
	t_solong	*sl;
	t_shot		*new_shot;
	// mlx_image_t	*img;

	sl = param;
	if (mlx_is_key_down(sl->mlx, MLX_KEY_SPACE) && sl->player->is_armed
		&& sl->player->timer <= 0)
	{
		new_shot = create_shot(sl);
		sl->shot = array_join_shot(sl->shot, new_shot);
		sl->player->timer = 10;
		place_shot(sl, new_shot);
	}
	if (!mlx_is_key_down(sl->mlx, MLX_KEY_SPACE) && sl->player->timer >= 0)
		sl->player->timer--;
	move_shot(sl);
	check_shot_validity(sl);
}

void	place_shot(t_solong *sl, t_shot *shot)
{
	if (shot->direction == 'W')
	{
		shot->x += 24;
		shot->y -= 10;
	}
	else if (shot->direction == 'S')
	{
		shot->x += 4;
		shot->y += 45;
	}
	else if (shot->direction == 'D')
	{
		shot->x += 45;
		shot->y += 23;
	}
	else if (shot->direction == 'A')
	{
		shot->x -= 10;
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
				if (sl->shot[i]->x < 0 || sl->shot[i]->x > sl->map->width_px
					|| sl->shot[i]->y < 0
					|| sl->shot[i]->y > sl->map->height_px
					|| check_hitbox_shot(sl, sl->shot[i]->x, sl->shot[i]->y))
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
					sl->shot[i]->y -= 10;
				if (sl->shot[i]->direction == 'S')
					sl->shot[i]->y += 10;
				if (sl->shot[i]->direction == 'D')
					sl->shot[i]->x += 10;
				if (sl->shot[i]->direction == 'A')
					sl->shot[i]->x -= 10;
				sl->shot[i]->img->instances[0].x = sl->shot[i]->x;
				sl->shot[i]->img->instances[0].y = sl->shot[i]->y;
			}
			i++;
		}
	}
}

// int	find_shot_off(t_solong *sl)
// {
// 	int	i;

// 	i = 0;
// 	if (sl->shot)
// 	{
// 		while (sl->shot[i])
// 		{
// 			if (sl->shot[i]->is_on == 0)
// 				return (i);
// 		}
// 	}
// 	return (-1);
// }


// void	delete_shot_off(t_solong *sl)
// {
// 	int	i;
// 	// int	index;

// 	// index = find_shot_off(sl);
// 	i = 0;
// 	if (sl->shot)
// 	{
// 		while (sl->shot[i])
// 		{
// 			if (sl->shot[i]->is_on == 0)
// 				// array_remove(sl->shot, index);
// 				ft_printf("remove\n");
// 			i++;
// 		}
// 	}
// }

t_shot	**array_remove(t_shot **array_shot, int	index)
{
	int		i;
	t_shot	**new_array;

	i = 0;
	if (array_shot)
		while (array_shot[i])
			i++;
	new_array = malloc(sizeof(t_shot *) * (i + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	if (array_shot)
	{
		while (array_shot[i])
		{
			if (i != index)
			{
				new_array[i] = array_shot[i];
				i++;
			}
		}
	}
	new_array[i + 1] = NULL;
	free_array_struct(array_shot);
	// free(array_shot);
	return (new_array);
}

void	free_array_struct(t_shot **array_shot)
{
	int	i;

	i = 0;
	while (array_shot[i])
		i++;
	while (i > 0)
		free(array_shot[i--]);
	free(array_shot);
}

t_shot	**array_join_shot(t_shot **array_shot, t_shot *shot)
{
	int		i;
	t_shot	**new_array;

	i = 0;
	if (array_shot)
		while (array_shot[i])
			i++;
	new_array = malloc(sizeof(t_shot *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	if (array_shot)
	{
		while (array_shot[i])
		{
			new_array[i] = array_shot[i];
			i++;
		}
	}
	new_array[i] = shot;
	new_array[i + 1] = NULL;
	free(array_shot);
	return (new_array);
}

t_shot	*create_shot(t_solong *sl)
{
	t_shot	*shot;

	shot = malloc(sizeof(t_shot));
	shot->img = mlx_texture_to_image(sl->mlx, sl->texture[12]);
	shot->x = sl->player->img->instances[0].x;
	shot->y = sl->player->img->instances[0].y;
	shot->direction = sl->player->direction;
	shot->is_on = 1;
	shot->width = 15;
	shot->height = 15;
	return (shot);
}
