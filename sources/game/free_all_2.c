/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:04:24 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/20 14:40:31 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	free_all(t_solong *sl)
{
	free_ennemy(sl);
	free_collectible(sl);
	free_shot(sl);
	free_solong(sl);
	free_textures(sl);
}

void	free_map(t_solong *sl)
{
	int	i;

	i = 0;
	while (sl->map->map[i])
	{
		free(sl->map->map[i]);
		i++;
	}
	free(sl->map->map);
	free(sl->map);
}
