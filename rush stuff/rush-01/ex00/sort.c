/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treineke <treineke@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:24:38 by treineke          #+#    #+#             */
/*   Updated: 2024/08/11 21:51:44 by treineke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort(int *arr, int size)
{
	int	was_changed;
	int	i;
	int	temp;

	i = 0;
	was_changed = 0;
	while (i < size - 1)
	{
		if (*(arr + i) < *(arr + i + 1))
		{
			temp = *(arr + i);
			*(arr + i) = *(arr + i + 1);
			*(arr + i + 1) = temp;
			was_changed = 1;
		}
		i++;
	}
	if (was_changed == 1)
		sort(arr, size);
}
