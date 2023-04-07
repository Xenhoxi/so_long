/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:28:48 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/07 00:05:10 by ljerinec         ###   ########.fr       */
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

	sl = param;
	vertical_move(sl);
	horizontal_move(sl);
	key_hook(sl);
}

void	run(t_solong *sl)
{
	sl->mlx = mlx_init(sl->map->width_px, sl->map->height_px, "so_long", true);
	if (!sl->mlx)
		exit(EXIT_FAILURE);
	draw(sl);
	draw_player(sl);
	create_c(sl);
	draw_c(sl);
	mlx_loop_hook(sl->mlx, check_hitbox_c, sl);
	mlx_loop_hook(sl->mlx, ft_hook, sl);
	mlx_loop(sl->mlx);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
