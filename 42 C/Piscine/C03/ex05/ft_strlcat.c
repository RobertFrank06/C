/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:37:14 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 13:57:34 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tempi;

	j = 0;
	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	if (i == size)
	{
		while (src[j] != '\0')
			j++;
		return (i + j);
	}
	tempi = i;
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (tempi + j);
}
