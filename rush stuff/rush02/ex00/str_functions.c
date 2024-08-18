/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:37:36 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/17 22:45:58 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (0);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*append_strings(const char *str1, const char *str2)
{
	int		i;
	int		j;
	int		total_len;
	char	*result;

	total_len = ft_strlen(str1) + ft_strlen(str2);
	result = (char *)malloc(total_len + 1);
	i = 0;
	j = 0;
	if (!result)
		return (NULL);
	while (i < ft_strlen(str1))
	{
		result[i] = str1[i];
		i++;
	}
	while (j < ft_strlen(str2))
	{
		result[ft_strlen(str1) + j] = str2[j];
		j++;
	}
	result[total_len] = '\0';
	return (result);
}

char	*create_modifiable_string(const char *str)
{
	int		i;
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	i	= 0;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
