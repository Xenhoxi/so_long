/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:31:25 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/06 16:11:52 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	texture_init(t_solong *sl)
{
	sl->texture = malloc(sizeof(mlx_texture_t *) * 7);
	sl->texture[0] = mlx_load_png("./images/hitman_up.png");
	sl->texture[1] = mlx_load_png("./images/hitman_down.png");
	sl->texture[2] = mlx_load_png("./images/hitman_left.png");
	sl->texture[3] = mlx_load_png("./images/hitman_right.png");
	sl->texture[4] = mlx_load_png("./images/box.png");
	sl->texture[5] = mlx_load_png("./images/grass.png");
	sl->texture[6] = mlx_load_png("./images/collectibles_0.png");
}

t_solong	*init_solong(void)
{
	t_solong	*sl;

	sl = malloc(sizeof(t_solong));
	sl->map = malloc(sizeof(t_map));
	sl->player = malloc(sizeof(t_player));
	sl->mlx = NULL;
	sl->texture = NULL;
	sl->player->height = 43;
	sl->player->width = 35;
	texture_init(sl);
	return (sl);
}
