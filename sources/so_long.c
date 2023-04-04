/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:28:48 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/04 14:51:29 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(void)
{
	t_solong	*solong;

	solong = init_solong();
	solong->map = parsing("sources/map/map.ber");
	checking(solong);
	init(solong);
	return (0);
}

void	texture_init(t_solong *solong)
{
	solong->texture = malloc(sizeof(mlx_texture_t *) * 6);
	solong->texture[0] = mlx_load_png("./images/hitman_up.png");
	solong->texture[1] = mlx_load_png("./images/hitman_down.png");
	solong->texture[2] = mlx_load_png("./images/hitman_left.png");
	solong->texture[3] = mlx_load_png("./images/hitman_right.png");
	solong->texture[4] = mlx_load_png("./images/tile_129.png");
	solong->texture[5] = mlx_load_png("./images/tile_01.png");
}

t_solong	*init_solong(void)
{
	t_solong	*sl;

	sl = malloc(sizeof(t_solong));
	sl->map = NULL;
	sl->mlx = NULL;
	sl->texture = NULL;
	sl->map_height = 64;
	sl->map_width = 64;
	sl->player_x = 0;
	sl->player_y = 0;
	sl->player_width = 35;
	sl->player_height = 43;
	texture_init(sl);
	// sl->player = mlx_new_image(sl->mlx, sl->map_width, sl->map_height);
	sl->player = mlx_texture_to_image(sl->mlx, sl->texture[3]);
	return (sl);
}

// function that change the direction of the player
void	change_direction(t_solong *sl, char c)
{
	int				x;
	int				y;

	y = sl->player->instances[0].y;
	x = sl->player->instances[0].x;
	if (c == 'W')
	{
		mlx_delete_image(sl->mlx, sl->player);
		sl->player = mlx_new_image(sl->mlx, sl->map_width, sl->map_height);
		sl->player = mlx_texture_to_image(sl->mlx, sl->texture[0]);
		mlx_image_to_window(sl->mlx, sl->player, x, y);
	}
	if (c == 'S')
	{
		mlx_delete_image(sl->mlx, sl->player);
		sl->player = mlx_new_image(sl->mlx, sl->map_width, sl->map_height);
		sl->player = mlx_texture_to_image(sl->mlx, sl->texture[1]);
		mlx_image_to_window(sl->mlx, sl->player, x, y);
	}
	if (c == 'A')
	{
		mlx_delete_image(sl->mlx, sl->player);
		sl->player = mlx_new_image(sl->mlx, sl->map_width, sl->map_height);
		sl->player = mlx_texture_to_image(sl->mlx, sl->texture[2]);
		mlx_image_to_window(sl->mlx, sl->player, x, y);
	}
	if (c == 'D')
	{
		mlx_delete_image(sl->mlx, sl->player);
		sl->player = mlx_new_image(sl->mlx, sl->map_width, sl->map_height);
		sl->player = mlx_texture_to_image(sl->mlx, sl->texture[3]);
		mlx_image_to_window(sl->mlx, sl->player, x, y);
	}
}

// void	ft_direction(void *param)
// {
// 	t_solong	*sl;
// 	mlx_t		*mlx;
// 	int			x;
// 	int			y;

// 	sl = param;
// 	mlx = sl->mlx;
// 	x = 0;
// 	y = 0;
// 	mlx_get_mouse_pos(mlx, &x, &y);
// }

void	ft_hook(void *param)
{
	t_solong	*sl;
	mlx_t		*mlx;
	int			key_pressed;

	sl = param;
	mlx = sl->mlx;
	key_pressed = 0;
	sl->player_x = sl->player->instances[0].x;
	sl->player_y = sl->player->instances[0].y;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, sl->player_x, sl->player_y - 2))
		{
			sl->player->instances[0].y = sl->player_y - 2;
			change_direction(sl, 'W');
		}
	}
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, sl->player_x, sl->player_y + 2))
		{
			sl->player->instances[0].y = sl->player_y + 2;
			change_direction(sl, 'S');
		}
	}
	if (!mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, sl->player_x - 2, sl->player_y))
		{
			sl->player->instances[0].x = sl->player_x - 2;
			change_direction(sl, 'A');
		}
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D) && !mlx_is_key_down(mlx, MLX_KEY_W)
		&& !mlx_is_key_down(mlx, MLX_KEY_A) && !mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (!check_hitbox(sl, sl->player_x + 2, sl->player_y))
		{
			sl->player->instances[0].x = sl->player_x + 2;
			change_direction(sl, 'D');
		}
	}
}

void	init(t_solong *sl)
{
	char	**map;

	map = sl->map;
	sl->mlx = mlx_init(sl->tile_width, sl->tile_heigth, "so_long", true);
	if (!sl->mlx)
		exit(EXIT_FAILURE);
	draw(sl);
	// draw_player(sl);
	// mlx_loop_hook(sl->mlx, ft_hook, sl);
	mlx_loop(sl->mlx);
}


void	print_char_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
