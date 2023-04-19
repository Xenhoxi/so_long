/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:12:29 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/19 03:01:34 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	collectible(void *param)
{
	t_solong	*sl;
	int			i;
	int			nb_c;

	sl = (t_solong *)param;
	i = 0;
	nb_c = count_spec_c(sl->map->map, 'C');
	check_hitbox_c(sl);
	while (i < count_c(sl->map->map))
	{
		if (nb_c == sl->player->nb_collec
			&& sl->collectible[i]->type == 'E'
			&& sl->collectible[i]->is_collected == -1)
		{
			mlx_image_to_window(sl->mlx, sl->collectible[i]->img,
				sl->collectible[i]->x, sl->collectible[i]->y);
			sl->collectible[i]->is_collected = 0;
		}
		i++;
	}
}

int	count_spec_c(char **map, char type)
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
			if (is_c(map[y][x]) == type)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

int	count_c(char **map)
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
			if (is_c(map[y][x]) > 0)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

t_collect	*init_c(t_solong *sl, int x, int y, char type)
{
	t_collect	*collectible;

	collectible = malloc(sizeof(t_collect));
	if (type == 'C')
		collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[10]);
	collectible->x = x * T_S;
	collectible->y = y * T_S;
	if (type == 'W')
	{
		collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[11]);
		collectible->x = x * T_S + 20;
		collectible->y = y * T_S + 25;
	}
	collectible->is_collected = 0;
	if (type == 'E')
	{
		collectible->img = mlx_texture_to_image(sl->mlx, sl->texture[18]);
		collectible->is_collected = -1;
	}
	collectible->type = type;
	collectible->current_img = 0;
	return (collectible);
}

void	create_c(t_solong *sl)
{
	char	**map;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	x = 0;
	map = sl->map->map;
	sl->collectible = malloc(sizeof(t_collect *) * (count_c(sl->map->map) + 1));
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_c(map[y][x]) > 0)
			{
				sl->collectible[i] = init_c(sl, x, y, is_c(map[y][x]));
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	sl->collectible[i] = NULL;
}
