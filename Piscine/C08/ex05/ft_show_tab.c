/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:58:37 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/20 14:18:02 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;
	char	*str;
	char	*copy;

	i = 0;
	while (par[i].str != 0)
	{
		str = par[i].str;
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		copy = par[i].copy;
		while (*copy)
			write(1, copy++, 1);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
