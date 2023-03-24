/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:02 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/24 12:30:55 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H

# define SOLONG_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

// parsing/parsing.c
char	**parsing(char *map);
int		selected_fd(char *map);
char	**array_join(char **array, char *line);

// parsing/map_checker.c
void	checking(char **map);
int		map_checking(char **map);
void	find_spawn(char **map, int *x, int *y);
int		coord_is_possible(char **map);


// parsing/map_checker_2.c
int		map_is_rectangle(char **map);
int		player_spawn(char **map);
int		map_is_closed(char **map);
int		map_exit(char **map);
int		map_collectible(char **map);

// parsing/map_checker_3.c
void	print_map(char **map, int **int_map);
int		check_side(int **int_map, int x, int y);
int		find_coord(char **map, int **int_map, int i);
int		coord_is_possible(char **map);
int		**map_in_int(char **map);

// parsing/utils.c
int		array_len(char **map);
void	error(void);

#endif