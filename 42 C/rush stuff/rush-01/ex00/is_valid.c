/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:27:44 by treineke          #+#    #+#             */
/*   Updated: 2024/08/12 21:11:45 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_coordinate(int grid[4][4], char axis);
int		is_in_array(int height, int arr[]);
void	print_grid(int grid[4][4]);
int		matches_pov(int height, int row[], int pov, int x);
int		*reverse(int *arr);

int	is_valid(int height, int grid[4][4], char *povs)
{
	int	x;
	int	y;
	int	row[4];
	int	col[4];
	int	i;

	x = get_coordinate(grid, 'x');
	y = get_coordinate(grid, 'y');
	i = 0;
	while (i < 4)
	{
		row[i] = grid[y][i];
		col[i] = grid[i][x];
		i++;
	}
	if (is_in_array(height, row)
		|| is_in_array(height, col)
		|| !matches_pov(height, row, povs[y * 2 + 16] - 48, x)
		|| !matches_pov(height, col, povs[x * 2 + 0] - 48, y)
		|| !matches_pov(height, reverse(row), povs[y * 2 + 24] - 48, 3 - x)
		|| !matches_pov(height, reverse(col), povs[x * 2 + 8] - 48, 3 - y))
		return (0);
	return (1);
}

int	get_coordinate(int grid[4][4], char axis)
{
	int	y;
	int	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (grid[y][x] == 0)
				break ;
			x++;
		}
		if (grid[y][x] == 0 && x < 4)
			break ;
		y++;
	}
	if (axis == 'x')
		return (x);
	return (y);
}

int	is_in_array(int height, int arr[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arr[i] == height)
			return (1);
		i++;
	}
	return (0);
}

// i =				ixxx
// num_of_blocks =	xNxx
// visible_blocks = xxVx
// max_height =		xxxM
int	matches_pov(int height, int row[], int pov, int x)
{
	int	all;

	all = 0;
	row[x] = height;
	if (row[0] == 0)
		return (1);
	while (all < 4000)
	{
		if (row[all / 1000] != 0)
			all += 100;
		if (row[all / 1000] > all % 10)
		{
			all = all / 10 * 10 + row[all / 1000];
			all += 10;
		}
		all += 1000;
	}
	row[x] = 0;
	if (pov - (all / 10 % 10) > 4 - (all / 100 % 10))
		return (0);
	if ((all / 10 % 10) > pov)
		return (0);
	return (1);
}

int	*reverse(int *arr)
{
	int	i;
	int	temp;

	i = 0;
	while (i < 2)
	{
		temp = arr[i];
		arr[i] = arr[3 - i];
		arr[3 - i] = temp;
		i++;
	}
	return (arr);
}
