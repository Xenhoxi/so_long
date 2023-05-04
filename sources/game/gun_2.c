/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:43:42 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/19 02:44:14 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

t_shot	**array_remove(t_shot **array_shot, int index)
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

t_shot	*create_shot(t_solong *sl, int _x, int _y, char dir)
{
	t_shot	*shot;

	shot = malloc(sizeof(t_shot));
	shot->img = mlx_texture_to_image(sl->mlx, sl->texture[12]);
	shot->x = _x;
	shot->y = _y;
	shot->direction = dir;
	shot->is_on = 1;
	shot->width = 15;
	shot->height = 15;
	return (shot);
}
