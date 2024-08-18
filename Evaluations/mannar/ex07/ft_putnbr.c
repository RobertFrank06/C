/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmannar <nmannar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:23:24 by nmannar           #+#    #+#             */
/*   Updated: 2024/08/04 16:38:58 by nmannar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	num_length(int nb)
{
	int	counter;

	if (nb < 0)
		nb *= -1;
	counter = 1;
	while (nb / 10 != 0)
	{
		counter++;
		nb /= 10;
	}
	return (counter);
}

void	ft_putnbr(int nb)
{
	int		num_len;
	int		tens;
	char	c;

	tens = 1;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	num_len = num_length(nb);
	while (num_len > 1)
	{
		tens *= 10;
		num_len--;
	}
	while (tens != 0)
	{
		c = (nb / tens) + '0';
		write(1, &c, 1);
		nb -= ((c - '0') * tens);
		tens /= 10;
	}
}
