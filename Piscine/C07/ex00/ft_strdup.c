/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:14:29 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/18 18:20:25 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		length;
	char	*dupstr;
	int		i;

	i = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	dupstr = (char *)malloc(length + 1);
	if (!dupstr)
		return (0);
	while (i < length)
	{
		dupstr[i] = src[i];
		i++;
	}
	dupstr[length] = '\0';
	return (dupstr);
}
