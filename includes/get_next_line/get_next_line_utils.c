/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:28:48 by ljerinec          #+#    #+#             */
/*   Updated: 2023/03/09 23:37:44 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeallspe(char **str)
{
	*str = 0;
	return (0);
}

char	*freeall(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
		return (*str);
	}
	return (NULL);
}

char	*doublefree(char *str, char **result)
{
	free(str);
	return (freeall(result));
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_backslash(char *save, int u)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n' || save[i] == '\0')
			return (1);
		i++;
	}
	if (save[i] == '\0' && (u < BUFFER_SIZE))
		return (1);
	return (0);
}
