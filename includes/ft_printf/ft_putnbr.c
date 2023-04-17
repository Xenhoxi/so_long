/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:35:28 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/26 21:35:55 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long n, int *size)
{
	char		modulo;
	static int	nb;

	nb = 0;
	if (n < 0)
	{
		ft_putchar('-', size);
		if (*size == -1)
			return ;
		n = -n;
	}
	if (n < 10 && !nb)
	{
		modulo = (n + 48);
		ft_putchar(modulo, size);
		if (*size == -1)
			nb = -1;
		return ;
	}
	else
		ft_putnbr(n / 10, size);
	if (!nb)
		ft_putnbr(n % 10, size);
}

void	ft_putunbr(unsigned int n, int *size)
{
	char		modulo;
	static int	nb;

	nb = 0;
	if (n < 10 && !nb)
	{
		modulo = (n + 48);
		ft_putchar(modulo, size);
		if (*size == -1)
			nb = -1;
		return ;
	}
	else
		ft_putunbr(n / 10, size);
	if (!nb)
		ft_putunbr(n % 10, size);
}
