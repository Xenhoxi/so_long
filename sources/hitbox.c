/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:36:59 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/04 16:28:52 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_hitbox(t_solong *sl, int player_x, int player_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (sl->map[y])
	{
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == '1')
			{
				if (player_x < (x * 64) + T_S
					&& player_x + sl->player_width > x * 64
					&& player_y < y * 64 + T_S
					&& player_y + sl->player_height > y * 64)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
