/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/04 16:06:04 by ljerinec         ###   ########.fr       */
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

// static mlx_image_t	*g_image;

typedef struct s_solong
{
	mlx_t			*mlx;
	mlx_texture_t	**texture;
	mlx_image_t		*player;
	char			**map;
	int				map_height;
	int				map_width;
	int				tile_width;
	int				tile_heigth;
	int				player_height;
	int				player_width;
	int				player_x;
	int				player_y;
}			t_solong;

// so_long.cs
void		print_char_map(char **map);
void		draw(t_solong *solong);
t_solong	*init_solong(void);
void		draw_player(t_solong *solong);

// hibox.c
int			check_hitbox(t_solong *sl, int p_x, int p_y);

// parsing/parsing.c
char		**parsing(char *map);
int			selected_fd(char *map);
char		**array_join(char **array, char *line);
void		init(t_solong *solong);

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

#endif