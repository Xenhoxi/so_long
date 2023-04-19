/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:26:46 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/19 02:31:47 by ljerinec         ###   ########.fr       */
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
