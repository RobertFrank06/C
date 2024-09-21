/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:21:09 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/21 14:49:45 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	i = 0;
	array = malloc((max - min) * sizeof(int));
	if (min >= max)
		return (NULL);
	while (min + i < max)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
