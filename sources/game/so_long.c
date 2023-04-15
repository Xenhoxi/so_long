/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:28:48 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/15 17:17:59 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	main(void)
{
	t_solong	*solong;

	solong = init_solong();
	solong->map->map = parsing("sources/map/map.ber");
	checking(solong);
	run(solong);
	return (0);
}

void	ft_hook(void *param)
{
	t_solong	*sl;

	sl = (t_solong *)param;
	if (sl->player->health > 0)
		move(sl);
	else
		change_img(sl, sl->player->x, sl->player->y, 17);
	key_hook(sl);
}

void	init(t_solong *sl)
{
	draw_map(sl);
	draw_player(sl);
	create_ennemy(sl);
	draw_ennemy(sl);
	create_c(sl);
	draw_c(sl);
}

void	run(t_solong *sl)
{
	sl->mlx = mlx_init(sl->map->width_px, sl->map->height_px, "so_long", true);
	if (!sl->mlx)
		exit(EXIT_FAILURE);
	init(sl);
	mlx_loop_hook(sl->mlx, check_hitbox_c, sl);
	mlx_loop_hook(sl->mlx, ft_hook, sl);
	mlx_loop_hook(sl->mlx, shot, sl);
	mlx_loop_hook(sl->mlx, ennemy, sl);
	ft_printf("OK!\n");
	mlx_loop(sl->mlx);
}
