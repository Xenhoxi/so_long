/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 03:44:57 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/19 03:56:56 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	free_textures(t_solong *sl)
{
	int	i;

	i = 0;
	while (sl->texture[i] && sl->texture)
	{
		if (sl->texture[i])
			mlx_delete_texture(sl->texture[i]);
		i++;
	}
	free(sl->texture);
}

void	free_ennemy(t_solong *sl)
{
	int	i;

	i = 0;
	while (sl->ennemy[i] && sl->ennemy)
	{
		if (sl->ennemy[i]->img)
			mlx_delete_image(sl->mlx, sl->ennemy[i]->img);
		free(sl->ennemy[i]);
		i++;
	}
	free(sl->ennemy);
}

void	free_collectible(t_solong *sl)
{
	int	i;

	i = 0;
	while (sl->collectible[i] && sl->collectible)
	{
		if (sl->collectible[i]->img)
			mlx_delete_image(sl->mlx, sl->collectible[i]->img);
		free(sl->collectible[i]);
		i++;
	}
	free(sl->collectible);
}

void	free_shot(t_solong *sl)
{
	int	i;

	i = 0;
	while (sl->shot[i] && sl->shot)
	{
		if (sl->shot[i]->img)
			mlx_delete_image(sl->mlx, sl->shot[i]->img);
		free(sl->shot[i]);
		i++;
	}
	free(sl->shot);
}

void	free_solong(t_solong *sl)
{
	free_map(sl);
	mlx_delete_image(sl->mlx, sl->player->img);
	mlx_delete_image(sl->mlx, sl->player->img_score);
	free(sl->player);
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
