/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:10:52 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/18 19:47:47 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*empty;

	empty = NULL;
	if (size == 0)
	{
		return (empty);
	}
	while (*strs && size > 0)
	{
		ft_strcat(*strs, sep);
		size--;
	}
	return (*strs);
}

int	main(void)
{
	char	*strs[3];
	char	*result;

	strs[0] = "hello";
	strs[1] = "hello1";
	strs[2] = "hello2";
	result = ft_strjoin(3, strs, "||");
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
