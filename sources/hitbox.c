/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:36:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/25 18:08:27 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_hitbox(t_solong *sl, int p_x, int p_y)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;

	x = 0;
	y = 0;
	player_x = p_x;
	player_y = p_y;
	while (sl->map[y])
	{
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == '1')
			{
				if (player_x < (x * 64) + TILE_SIZE && player_x + sl->player_width > x * 64 && player_y < y * 64 + TILE_SIZE && player_y + sl->player_height > y * 64)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
