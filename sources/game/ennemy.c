/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:08 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/11 15:58:32 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	create_ennemy(t_solong *sl)
{
	int		nb_ennemy;
	int		x;
	int		y;
	int		i;

	nb_ennemy = count_ennemy(sl->map->map);
	i = 0;
	y = 0;
	x = 0;
	sl->ennemy = malloc(sizeof(t_collect *) * nb_ennemy + 1);
	while (sl->map->map[y])
	{
		while (sl->map->map[y][x])
		{
			if (sl->map->map[y][x] == 'M')
			{
				sl->ennemy[i] = init_ennemy(sl, x, y);
				ft_printf("Ennemy cree !\n");
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	sl->ennemy[i] = NULL;
}

t_ennemy	*init_ennemy(t_solong *sl, int _x, int _y)
{
	t_ennemy	*ennemy;

	ennemy = malloc(sizeof(t_ennemy));
	ennemy->img = mlx_texture_to_image(sl->mlx, sl->texture[13]);
	ennemy->direction = 'W';
	ennemy->health = 100;
	ennemy->is_on = 1;
	ennemy->x = _x * T_S;
	ennemy->y = _y * T_S;
	ennemy->width = 49;
	ennemy->height = 49;
	return (ennemy);
}

int	count_ennemy(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'M')
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

void	draw_ennemy(t_solong *sl)
{
	int	i;
	// int	count;

	i = 0;
	// count = count_c(sl->map->map);
	while (sl->ennemy[i])
	{
		if (sl->ennemy[i]->is_on)
			mlx_image_to_window(sl->mlx, sl->ennemy[i]->img,
				sl->ennemy[i]->x, sl->ennemy[i]->y);
		i++;
	}
}
