/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:21:09 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/18 18:49:55 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc((max - min) * sizeof(int));
	if (min >= max)
		return (NULL);
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
