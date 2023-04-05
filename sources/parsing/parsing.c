/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:08:48 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/05 13:24:51 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int	selected_fd(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (fd);
}

char	**parsing(char *map)
{
	char	**tab;
	char	*line;
	int		fd;

	tab = NULL;
	fd = selected_fd(map);
	line = get_next_line(fd);
	while (line)
	{
		tab = array_join(tab, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (tab);
}

char	**array_join(char **array, char *line)
{
	int		i;
	char	**new_array;
	int		len;

	i = 0;
	if (array != NULL)
		while (array[i])
			i++;
	len = i;
	new_array = malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	new_array[++i] = NULL;
	free(array);
	return (new_array);
}
