/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:49:07 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/11 21:51:18 by treineke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(int grid[4][4])
{
	int	y;
	int	x;
	int	output;

	y = 0;
	x = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			output = grid[y][x] + 48;
			write(1, &output, 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
