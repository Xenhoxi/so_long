/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:46:07 by ljerinec          #+#    #+#             */
/*   Updated: 2023/04/15 16:45:16 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*all_before_backslash_n(char *str);
char	*all_after_backslash_n(char *str);
char	*ft_strjoin_gnl(char *str, char *buffer, int len);
char	*freeall(char **str);
char	*freeallspe(char **str);
char	*doublefree(char *str, char **result);
int		ft_strlen_gnl(char *str);
int		check_backslash(char *save, int u);

#endif