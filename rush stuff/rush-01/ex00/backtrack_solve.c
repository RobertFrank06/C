/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:02:51 by treineke          #+#    #+#             */
/*   Updated: 2024/08/12 17:49:07 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	generate_options(int *options_arr, int grid[4][4], char *povs);
void	sort(int *arr, int size);
int		is_valid(int height, int grid[4][4], char *povs);

int	backtrack_solve(int grid[4][4], char *povs, int x, int y)
{
	int	options_arr[5];
	int	i;

	if (x == 4)
	{
		y++;
		x = 0;
	}
	generate_options(options_arr, grid, povs);
	sort(options_arr, 5);
	i = 0;
	while (options_arr[i])
	{
		grid[y][x] = options_arr[i];
		if (y == 3 && x == 3)
			return (1);
		if (backtrack_solve(grid, povs, x + 1, y))
			return (1);
		i++;
	}
	grid[y][x] = 0;
	return (0);
}

void	generate_options(int *options_arr, int grid[4][4], char *povs)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (is_valid(4 - i, grid, povs))
		{
			options_arr[i] = 4 - i;
		}
		else
			options_arr[i] = 0;
		i++;
	}
}
