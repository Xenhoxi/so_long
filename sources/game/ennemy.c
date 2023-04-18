/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:08 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/18 15:09:18 by ljerinec         ###   ########.fr       */
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
	while (sl->ennemy[i])
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
			sl->ennemy[i]->timer = 100;
		}
		sl->ennemy[i]->timer--;
		i++;
	}
}

int	player_in_view(t_solong *sl, t_ennemy *ennemy)
{
	int	p_x;
	int	p_y;
	int	nb_case;

	nb_case = fov_of_robot(sl, ennemy);
	p_x = sl->player->img->instances[0].x;
	p_y = sl->player->img->instances[0].y;
	if (ennemy->direction == 'D')
	{
		if (p_x < (ennemy->x + nb_case * T_S)
			&& p_x + sl->player->width > ennemy->x + T_S
			&& p_y < ennemy->y + T_S
			&& p_y + sl->player->height > ennemy->y)
			return (1);
	}
	else if (ennemy->direction == 'A')
	{
		if (p_x > (ennemy->x - nb_case * T_S)
			&& p_x + sl->player->width < (ennemy->x + T_S)
			&& p_y < ennemy->y + T_S
			&& p_y + sl->player->height > ennemy->y)
			return (1);
	}
	else if (ennemy->direction == 'W')
	{
		if (p_x < (ennemy->x + T_S)
			&& p_x + sl->player->width > ennemy->x
			&& p_y > (ennemy->y - nb_case * T_S)
			&& p_y + sl->player->height < ennemy->y)
			return (1);
	}
	else if (ennemy->direction == 'S')
	{
		if (p_x < (ennemy->x + T_S)
			&& (p_x + sl->player->width) > ennemy->x
			&& p_y < (ennemy->y + nb_case * T_S)
			&& (p_y + sl->player->height) > ennemy->y)
			return (1);
	}
	return (0);
}

int	fov_of_robot(t_solong *sl, t_ennemy *e)
{
	int		nb_case;
	char	**map;
	int		i;
	int		x;
	int		y;

	i = 1;
	map = sl->map->map;
	nb_case = 1;
	x = e->x / T_S;
	y = e->y / T_S;
	if (e->direction == 'W')
		while (map[y - ++i][x] == '0' || map[y - i][x] == 'C'
			|| map[y - i][x] == 'W' || map[y - i][x] == 'M')
			nb_case++;
	else if (e->direction == 'S')
		while (map[y + ++i][x] == '0' || map[y + i][x] == 'C'
			|| map[y + i][x] == 'W' || map[y + i][x] == 'M')
			nb_case++;
	else if (e->direction == 'D')
		while (map[y][x + ++i] == '0' || map[y][x + i] == 'C'
			|| map[y][x + i] == 'W' || map[y][x + i] == 'M')
			nb_case++;
	else if (e->direction == 'A')
		while (map[y][x - ++i] == '0' || map[y][x - i] == 'C'
			|| map[y][x - i] == 'W' || map[y][x - i] == 'M')
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
	ennemy->x = _x * T_S + 7 ;
	ennemy->y = _y * T_S + 7;
	ennemy->width = 49;
	ennemy->height = 49;
	return (ennemy);
}

char	check_direction(t_solong *sl, int _x, int _y)
{
	int		*tab;
	int		i;
	char	**map;

	map = sl->map->map;
	tab = malloc(sizeof(int) * 4);
	i = 0;
	while (i < 4)
		tab[i++] = 0;
	i = _x;
	while (map[_y][--i] == '0' || map[_y][i] == 'C' || map[_y][i] == 'W')
		tab[0]++;
	i = _x;
	while (map[_y][++i] == '0' || map[_y][i] == 'C' || map[_y][i] == 'W')
		tab[1]++;
	i = _y;
	while (map[--i][_x] == '0' || map[i][_x] == 'C' || map[i][_x] == 'W')
		tab[2]++;
	i = _y;
	while (map[++i][_x] == '0' || map[i][_x] == 'C' || map[i][_x] == 'W')
		tab[3]++;
	return (choose_direction(tab));
}

char	choose_direction(int *tab)
{
	int	i;
	int	mem;
	int	high;

	i = 1;
	high = tab[0];
	mem = 0;
	while (i < 4)
	{
		if (tab[i] > high)
		{
			mem = i;
			high = tab[i];
		}
		i++;
	}
	free(tab);
	if (mem == 0)
		return ('A');
	else if (mem == 1)
		return ('D');
	else if (mem == 2)
		return ('W');
	else
		return ('S');
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

	i = 0;
	while (sl->ennemy[i])
	{
		if (sl->ennemy[i]->is_on)
			mlx_image_to_window(sl->mlx, sl->ennemy[i]->img,
				sl->ennemy[i]->x, sl->ennemy[i]->y);
		i++;
	}
}
