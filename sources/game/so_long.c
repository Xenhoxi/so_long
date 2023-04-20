/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:28:48 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/20 13:09:40 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	main(int argc, char **argv)
{
	t_solong	*solong;

	if (argc != 2)
		exit(1);
	solong = init_solong();
	solong->map->map = parsing(argv[1]);
	checking(solong);
	run(solong);
	return (0);
}

void	ft_hook(void *param)
{
	t_solong	*sl;
	char		*str;

	sl = (t_solong *)param;
	str = ft_strjoin(" Score : ", ft_itoa(sl->player->score));
	if (sl->player->health > 0 && sl->game_on)
		move(sl);
	else if (sl->player->health < 0 && sl->game_on == 1)
		losing_screen(sl);
	if (sl->player->img_score == NULL)
		sl->player->img_score = mlx_put_string(sl->mlx, str, 0, 0);
	else
	{
		mlx_delete_image(sl->mlx, sl->player->img_score);
		sl->player->img_score = mlx_put_string(sl->mlx, str, 0, 0);
		mlx_resize_image(sl->player->img_score, 200, 40);
	}
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

void	delta_time(void *param)
{
	t_solong	*sl;
	double		current_time;
	double		fps;

	fps = 60;
	sl = (t_solong *)param;
	current_time = mlx_get_time();
	sl->dt = current_time - sl->prev_dt;
	sl->prev_dt = current_time;
}

void	run(t_solong *sl)
{
	sl->mlx = mlx_init(sl->map->width_px, sl->map->height_px, "so_long", true);
	if (!sl->mlx)
		exit(EXIT_FAILURE);
	init(sl);
	mlx_loop_hook(sl->mlx, collectible, sl);
	mlx_loop_hook(sl->mlx, ft_hook, sl);
	mlx_loop_hook(sl->mlx, ennemy, sl);
	mlx_loop_hook(sl->mlx, shot, sl);
	mlx_loop_hook(sl->mlx, delta_time, sl);
	mlx_loop(sl->mlx);
	free_all(sl);
	ft_printf("OK!\n");
}
