/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmannar <nmannar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:08:58 by nmannar           #+#    #+#             */
/*   Updated: 2024/08/04 16:20:11 by nmannar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pos_two_digit_num(int n)
{
	char	a;

	if (n >= 0)
	{
		if (n < 100)
		{
			a = n / 10 + '0';
			write(1, &a, 1);
			a = n % 10 + '0';
			write(1, &a, 1);
		}
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			print_pos_two_digit_num(i);
			write(1, " ", 1);
			print_pos_two_digit_num(j);
			j++;
			if (i != 98)
				write(1, ", ", 2);
		}
		i++;
	}
}
