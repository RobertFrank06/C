/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:24:09 by treineke          #+#    #+#             */
/*   Updated: 2024/08/11 21:50:30 by treineke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid_input(int argc, char *argv[]);
void	clear_grid(int grid[4][4]);
int		backtrack_solve(int grid[4][4], char *povs, int x, int y);
void	print_grid(int grid[4][4]);

int	main(int argc, char *argv[])
{
	int	grid[4][4];

	if (!is_valid_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	clear_grid(grid);
	if (!backtrack_solve(grid, argv[1], 0, 0))
	{
		write(2, "Error\n", 6);
		return (2);
	}
	print_grid(grid);
	return (0);
}
