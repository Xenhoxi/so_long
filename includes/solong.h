/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/15 17:17:31 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H

# define SOLONG_H

# define T_S 64

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	mlx_image_t	*img;
	int			x;
	int			y;
	int			health;
	char		direction;
	int			is_armed;
	int			height;
	int			width;
	int			timer;
	int			score;
}			t_player;

typedef struct s_collect
{
	mlx_image_t	*img;
	int			x;
	int			y;
	char		type;
	int			is_collected;
	int			current_img;
}			t_collect;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		height;
	int		width;
	int		height_px;
	int		width_px;
}			t_map;

typedef struct s_shot
{
	mlx_image_t	*img;
	int			x;
	int			y;
	char		direction;
	int			is_on;
	int			height;
	int			width;
}			t_shot;

typedef struct s_ennemy
{
	mlx_image_t	*img;
	int			x;
	int			y;
	int			health;
	char		direction;
	int			timer;
	int			is_on;
	int			height;
	int			width;
}			t_ennemy;

typedef struct s_solong
{
	mlx_t			*mlx;
	mlx_texture_t	**texture;
	t_player		*player;
	t_map			*map;
	t_collect		**collectible;
	t_shot			**shot;
	t_ennemy		**ennemy;
}			t_solong;

// so_long.cs
void		print_char_map(char **map);
void		draw(t_solong *solong);
void		draw_player(t_solong *solong);
void		run(t_solong *solong);

// game/drawing.c
void		draw_map(t_solong *sl);
void		draw_player(t_solong *sl);

// game/collectible.c
int			count_c(char **map);
void		create_c(t_solong *sl);
char		is_c(char type);
void		draw_c(t_solong *sl);
t_collect	*init_c(t_solong *sl, int x, int y, char type);

// game/hibox.c
int			check_hitbox(t_solong *sl, int player_x, int player_y);
void		check_hitbox_c(void	*param);
int			check_hitbox_shot(t_solong *sl, int player_x, int player_y);
int			check_player(t_solong *sl, int sx, int sy, int is_shot);

// game/move.c
void		move(t_solong *sl);
void		check_left(t_solong *sl, int player_x, int player_y);
void		check_right(t_solong *sl, int player_x, int player_y);
void		check_up(t_solong *sl, int player_x, int player_y);
void		check_down(t_solong *sl, int player_x, int player_y);

// game/move_2.c
void		key_hook(t_solong *sl);
void		change_img(t_solong *sl, int x, int y, int i);
void		change_direction(t_solong *sl, char direction);

// game/gun.c
void		shot(void *param);
t_shot		**array_join_shot(t_shot **array_proj, t_shot *shot);
t_shot		*create_shot(t_solong *sl, int _x, int _y, char dir);
void		move_shot(t_solong *sl);
void		check_shot_validity(t_solong *sl);
void		delete_shot_off(t_solong *sl);
void		place_shot(t_solong *sl, t_shot *shot);
void		free_array_struct(t_shot **array_shot);
t_shot		**array_remove(t_shot **array_shot, int index);
void		shot_a_shot(t_solong *sl, int _x, int _y, char dir);

// game/ennemy.c
void		create_ennemy(t_solong *sl);
int			count_ennemy(char **map);
t_ennemy	*init_ennemy(t_solong *sl, int _x, int _y);
void		draw_ennemy(t_solong *sl);
int			check_ennemy(t_solong *sl, int sx, int sy, int is_shot);
void		ennemy(void	*param);
char		check_direction(t_solong *sl, int _x, int _y);
char		choose_direction(int *tab);
int			player_in_view(t_solong *sl, t_ennemy *ennemy);
int			fov_of_robot(t_solong *sl, t_ennemy *e);

// game/init.c
t_solong	*init_solong(void);
void		texture_init(t_solong *solong);

// parsing/parsing.c
char		**parsing(char *map);
int			selected_fd(char *map);
char		**array_join(char **array, char *line);

// parsing/map_checker.c
void		checking(t_solong *solong);
int			map_checking(char **map);
int			map_is_rectangle(char **map);
int			player_spawn(char **map);
int			map_is_closed(char **map);

// parsing/map_checker_2.c
int			map_exit(char **map);
int			map_collectible(char **map);
int			coord_is_possible(char **map);
void		find_spawn(char **map, int *x, int *y);
void		free_int_map(int **int_map);

// parsing/map_checker_3.c
int			check_side(int **int_map, int x, int y);
int			find_coord(char **map, int **int_map, int i);
int			coord_is_possible(char **map);
int			**map_in_int(char **map);
int			check_all(char **map, int **int_map);

// parsing/utils.c
int			array_len(char **map);
void		error(void);
void		print_map(char **map, int **int_map);
void		free_2d_char_array(char **map);
void		print_char_map(char **map);

#endif