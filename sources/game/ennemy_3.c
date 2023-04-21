/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:23:45 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/21 12:24:11 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	check_s(t_solong *sl, t_ennemy *ennemy, int nb_case)
{
	int	p_x;
	int	p_y;

	p_x = sl->player->img->instances[0].x;
	p_y = sl->player->img->instances[0].y;
	if (p_x < (ennemy->x + T_S)
		&& (p_x + sl->player->width) > ennemy->x
		&& p_y < (ennemy->y + nb_case * T_S)
		&& (p_y + sl->player->height) > ennemy->y)
		return (1);
	return (0);
}

int	check_w(t_solong *sl, t_ennemy *ennemy, int nb_case)
{
	int	p_x;
	int	p_y;

	p_x = sl->player->img->instances[0].x;
	p_y = sl->player->img->instances[0].y;
	if (p_x < (ennemy->x + T_S)
		&& p_x + sl->player->width > ennemy->x
		&& p_y > (ennemy->y - nb_case * T_S)
		&& p_y + sl->player->height < ennemy->y)
		return (1);
	return (0);
}

int	check_a(t_solong *sl, t_ennemy *ennemy, int nb_case)
{
	int	p_x;
	int	p_y;

	p_x = sl->player->img->instances[0].x;
	p_y = sl->player->img->instances[0].y;
	if (p_x > (ennemy->x - nb_case * T_S)
		&& p_x + sl->player->width < (ennemy->x + T_S)
		&& p_y < ennemy->y + T_S && p_y + sl->player->height > ennemy->y)
		return (1);
	return (0);
}

int	check_d(t_solong *sl, t_ennemy *ennemy, int nb_case)
{
	int	p_x;
	int	p_y;

	p_x = sl->player->img->instances[0].x;
	p_y = sl->player->img->instances[0].y;
	if (p_x < (ennemy->x + nb_case * T_S)
		&& p_x + sl->player->width > ennemy->x + T_S
		&& p_y < ennemy->y + T_S && p_y + sl->player->height > ennemy->y)
		return (1);
	return (0);
}
