/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmannar <nmannar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:43:27 by nmannar           #+#    #+#             */
/*   Updated: 2024/08/04 17:49:35 by nmannar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ascending(char *arr, char start, int size)
{
	int		i;
	char	end;

	i = 0;
	end = start + size;
	while (start < end)
	{
		arr[i] = start;
		start++;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];
	int		i;
	int		num;
	int		max;

	ascending(comb, '0', n);
	i = n;
	while (i > 0)
	{
		write(1, comb, n);
		max = 10;
		i = n;
		while (i--)
		{
			num = comb[i] - '0';
			if (num < --max)
			{
				max--;
				while ((i - 1) < n)
					comb[i++] = (++num) + '0';
				write(1, ", ", 2);
				break ;
			}
		}
	}
}
