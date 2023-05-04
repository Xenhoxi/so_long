/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:08 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/26 13:46:11 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	ennemy(void	*param)
{
	t_solong	*sl;
	int			i;
	int			x;
	int			y;

	i = 0;
	sl = (t_solong *)param;
	while (sl->ennemy[i] && sl->game_on == 1)
	{
		x = sl->ennemy[i]->x;
		y = sl->ennemy[i]->y;
		if (sl->ennemy[i]->is_on == 0)
		{
			mlx_delete_image(sl->mlx, sl->ennemy[i]->img);
			sl->ennemy[i]->img = NULL;
		}
		else if (player_in_view(sl, sl->ennemy[i]) && sl->ennemy[i]->timer <= 0
			&& sl->player->health > 0)
		{
			shot_a_shot(sl, x, y, sl->ennemy[i]->direction);
			sl->ennemy[i]->timer = 50;
		}
		sl->ennemy[i]->timer -= 7 * sl->dt;
		i++;
	}
}

int	player_in_view(t_solong *sl, t_ennemy *ennemy)
{
	int	nb_case;

	nb_case = fov_of_robot(ennemy, 1, sl->map->map);
	if (ennemy->direction == 'D')
		if (check_d(sl, ennemy, nb_case) == 1)
			return (1);
	if (ennemy->direction == 'A')
		if (check_a(sl, ennemy, nb_case) == 1)
			return (1);
	if (ennemy->direction == 'W')
		if (check_w(sl, ennemy, nb_case) == 1)
			return (1);
	if (ennemy->direction == 'S')
		if (check_s(sl, ennemy, nb_case) == 1)
			return (1);
	return (0);
}

int	fov_of_robot(t_ennemy *e, int i, char **map)
{
	int		nb_case;
	int		t[2];

	nb_case = 1;
	t[0] = e->x / T_S;
	t[1] = e->y / T_S;
	if (e->direction == 'W')
		while (map[t[1] - ++i][t[0]] == '0' || map[t[1] - i][t[0]] == 'C'
			|| map[t[1] - i][t[0]] == 'W' || map[t[1] - i][t[0]] == 'M')
			nb_case++;
	else if (e->direction == 'S')
		while (map[t[1] + ++i][t[0]] == '0' || map[t[1] + i][t[0]] == 'C'
			|| map[t[1] + i][t[0]] == 'W' || map[t[1] + i][t[0]] == 'M')
			nb_case++;
	else if (e->direction == 'D')
		while (map[t[1]][t[0] + ++i] == '0' || map[t[1]][t[0] + i] == 'C'
			|| map[t[1]][t[0] + i] == 'W' || map[t[1]][t[0] + i] == 'M')
			nb_case++;
	else if (e->direction == 'A')
		while (map[t[1]][t[0] - ++i] == '0' || map[t[1]][t[0] - i] == 'C'
			|| map[t[1]][t[0] - i] == 'W' || map[t[1]][t[0] - i] == 'M')
			nb_case++;
	return (nb_case + 1);
}

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
	sl->ennemy = malloc(sizeof(t_collect *) * (nb_ennemy + 1));
	while (sl->map->map[y])
	{
		while (sl->map->map[y][x])
		{
			if (sl->map->map[y][x] == 'M')
			{
				sl->ennemy[i] = init_ennemy(sl, x, y);
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
	ennemy->direction = check_direction(sl, _x, _y);
	if (ennemy->direction == 'A')
		ennemy->img = mlx_texture_to_image(sl->mlx, sl->texture[13]);
	else if (ennemy->direction == 'D')
		ennemy->img = mlx_texture_to_image(sl->mlx, sl->texture[14]);
	else if (ennemy->direction == 'W')
		ennemy->img = mlx_texture_to_image(sl->mlx, sl->texture[15]);
	else if (ennemy->direction == 'S')
		ennemy->img = mlx_texture_to_image(sl->mlx, sl->texture[16]);
	ennemy->health = 100;
	ennemy->is_on = 1;
	ennemy->timer = 0;
	ennemy->x = _x * T_S + 7 ;
	ennemy->y = _y * T_S + 7;
	ennemy->width = 49;
	ennemy->height = 49;
	return (ennemy);
}
