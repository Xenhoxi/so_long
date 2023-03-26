/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:28:48 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/26 05:04:00 by ljerinec         ###   ########.fr       */
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

t_solong	*init_solong(void)
{
	t_solong	*solong;

	solong = malloc(sizeof(t_solong));
	solong->map = NULL;
	solong->mlx = NULL;
	solong->map_height = 0;
	solong->map_width = 0;
	solong->player_x = 0;
	solong->player_y = 0;
	solong->player_width = 35;
	solong->player_height = 43;
	return (solong);
}

// function that change the direction of the player
void	change_direction(t_solong *sl, char c)
{
	mlx_texture_t	**texture;
	int				x;
	int				y;

	y = g_image->instances[0].y;
	x = g_image->instances[0].x;
	texture = malloc(sizeof(mlx_texture_t *) * 4);
	texture[0] = mlx_load_png("./images/hitman_up.png");
	texture[1] = mlx_load_png("./images/hitman_down.png");
	texture[2] = mlx_load_png("./images/hitman_left.png");
	texture[3] = mlx_load_png("./images/hitman_rigth.png");
	if (c == 'W')
	{
		mlx_delete_image(sl->mlx, g_image);
		g_image = mlx_new_image(sl->mlx, TILE_SIZE, TILE_SIZE);
		g_image = mlx_texture_to_image(sl->mlx, texture[0]);
		mlx_image_to_window(sl->mlx, g_image, x, y);
	}
	else if (c == 'S')
	{
		mlx_delete_image(sl->mlx, g_image);
		g_image = mlx_new_image(sl->mlx, TILE_SIZE, TILE_SIZE);
		g_image = mlx_texture_to_image(sl->mlx, texture[1]);
		mlx_image_to_window(sl->mlx, g_image, x, y);
	}
	else if (c == 'A')
	{
		mlx_delete_image(sl->mlx, g_image);
		g_image = mlx_new_image(sl->mlx, TILE_SIZE, TILE_SIZE);
		g_image = mlx_texture_to_image(sl->mlx, texture[2]);
		mlx_image_to_window(sl->mlx, g_image, x, y);
	}
	else if (c == 'D')
	{
		mlx_delete_image(sl->mlx, g_image);
		g_image = mlx_new_image(sl->mlx, TILE_SIZE, TILE_SIZE);
		g_image = mlx_texture_to_image(sl->mlx, texture[3]);
		mlx_image_to_window(sl->mlx, g_image, x, y);
	}
}

void	ft_direction(void *param)
{
	// change_direction(sl, 'W');
}

void	ft_hook(void *param)
{
	t_solong	*sl;
	mlx_t		*mlx;
	int			key_pressed;

	sl = param;
	mlx = sl->mlx;
	key_pressed = 0;
	sl->player_x = g_image->instances[0].x;
	sl->player_y = g_image->instances[0].y;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		if (!check_hitbox(sl, sl->player_x, sl->player_y - 2))
			g_image->instances[0].y -= 2;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		if (!check_hitbox(sl, sl->player_x, sl->player_y + 2))
			g_image->instances[0].y += 2;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		if (!check_hitbox(sl, sl->player_x - 2, sl->player_y))
		g_image->instances[0].x -= 2;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		if (!check_hitbox(sl, sl->player_x + 2, sl->player_y))
		g_image->instances[0].x += 2;
}

void	init(t_solong *sl)
{
	char	**map;

	map = sl->map;
	sl->mlx = mlx_init(sl->tile_width, sl->tile_heigth, "so_long", true);
	if (!sl->mlx)
		exit(EXIT_FAILURE);
	draw(sl);
	draw_player(sl);
	mlx_loop_hook(sl->mlx, ft_hook, sl);
	mlx_loop(sl->mlx);
}

void	draw(t_solong *solong)
{
	mlx_texture_t *texture = mlx_load_png("./images/tile_129.png");
	mlx_texture_t *texturesol = mlx_load_png("./images/tile_01.png");
	mlx_image_t *img = mlx_texture_to_image(solong->mlx, texture);
	mlx_image_t *imgsol = mlx_texture_to_image(solong->mlx, texturesol);
	char	**map;
	int		x;
	int		y;

	map = solong->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] != '1')
				mlx_image_to_window(solong->mlx, imgsol, (x * 64), (y * 64));
			if (map[y][x] == '1')
			{
				mlx_image_to_window(solong->mlx, imgsol, (x * 64), (y * 64));
				mlx_image_to_window(solong->mlx, img, (x * 64), (y * 64));
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_player(t_solong *solong)
{
	mlx_texture_t *player = mlx_load_png("./images/hitman_rigth.png");
	char	**map;
	int		x;
	int		y;

	g_image = mlx_texture_to_image(solong->mlx, player);
	map = solong->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				mlx_image_to_window(solong->mlx, g_image, (x * 64), (y * 64));
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(solong->mlx, g_image, (x * 64), (y * 64));
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
