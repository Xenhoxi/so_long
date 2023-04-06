/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:20:01 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/06 14:29:21 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	array_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	error(void)
{
	exit(1);
}

void	print_map(char **map, int **int_map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			printf("%d", int_map[x][y]);
			y++;
		}
		printf("\n");
		y = 0;
		x++;
	}
}

void	free_2d_char_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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
