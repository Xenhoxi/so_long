/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:45:19 by ljerinec          #+#    #+#             */
/*   Updated: 2023/02/07 16:02:26 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	temp = (*lst);
	if ((*lst) != NULL)
		(*lst) = (*lst)->next;
	else
		(*lst) = NULL;
	if ((*lst))
		(*lst)->prev = 0;
	free(temp);
}
