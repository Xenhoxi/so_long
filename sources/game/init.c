/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:31:25 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/20 11:45:41 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	texture_init(t_solong *sl)
{
	sl->texture = malloc(sizeof(mlx_texture_t *) * 20);
	sl->texture[0] = mlx_load_png("./images/hitman_up.png");
	sl->texture[1] = mlx_load_png("./images/hitman_down.png");
	sl->texture[2] = mlx_load_png("./images/hitman_left.png");
	sl->texture[3] = mlx_load_png("./images/hitman_right.png");
	sl->texture[4] = mlx_load_png("./images/hitman_gun_up.png");
	sl->texture[5] = mlx_load_png("./images/hitman_gun_down.png");
	sl->texture[6] = mlx_load_png("./images/hitman_gun_left.png");
	sl->texture[7] = mlx_load_png("./images/hitman_gun_right.png");
	sl->texture[8] = mlx_load_png("./images/box.png");
	sl->texture[9] = mlx_load_png("./images/grass.png");
	sl->texture[10] = mlx_load_png("./images/collectibles_0.png");
	sl->texture[11] = mlx_load_png("./images/weapon_left.png");
	sl->texture[12] = mlx_load_png("./images/bullet.png");
	sl->texture[13] = mlx_load_png("./images/robot_left.png");
	sl->texture[14] = mlx_load_png("./images/robot_right.png");
	sl->texture[15] = mlx_load_png("./images/robot_up.png");
	sl->texture[16] = mlx_load_png("./images/robot_down.png");
	sl->texture[17] = mlx_load_png("./images/blood.png");
	sl->texture[18] = mlx_load_png("./images/exit.png");
	sl->texture[19] = NULL;
}

t_solong	*init_solong(void)
{
	t_solong	*sl;

	sl = malloc(sizeof(t_solong));
	sl->map = malloc(sizeof(t_map));
	sl->player = malloc(sizeof(t_player));
	sl->mlx = NULL;
	sl->texture = NULL;
	sl->shot = NULL;
	sl->ennemy = NULL;
	sl->game_on = 1;
	sl->dt = 0;
	sl->prev_dt = 0;
	sl->player->height = 43;
	sl->player->width = 43;
	sl->player->is_armed = 0;
	sl->player->timer = 0;
	sl->player->health = 100;
	sl->player->score = 0;
	sl->player->nb_collec = 0;
	texture_init(sl);
	return (sl);
}
