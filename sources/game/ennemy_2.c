/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:37:40 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/19 02:38:09 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

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
