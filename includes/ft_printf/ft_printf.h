/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:05:20 by ljerinec          #+#    #+#             */
/*   Updated: 2022/11/26 21:32:56 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(char *s, int *size);
void	ft_putchar(int c, int *size);
void	ft_putnbr(long long n, int *size);
void	ft_putnbr_hexa(unsigned long nbr, const char format, int *size);
void	ft_putunbr(unsigned int n, int *size);

#endif