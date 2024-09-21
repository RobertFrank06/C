/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:04:20 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/04 22:01:20 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	first;
	int	tmp;
	int	loop;

	first = 0;
	loop = 0;
	while (loop < size - 1)
	{
		first = 0;
		while (first < size - loop - 1)
		{
			if (tab[first] > tab[first + 1])
			{
				tmp = tab[first];
				tab[first] = tab[first + 1];
				tab[first + 1] = tmp;
			}
			first++;
		}
		loop++;
	}
}
