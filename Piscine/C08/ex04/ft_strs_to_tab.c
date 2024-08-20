/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:48:29 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/20 13:57:08 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dst;
	int		i;

	len = ft_strlen(src);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	free_stock_str(struct s_stock_str *tab, int index)
{
	while (index > 0)
	{
		index--;
		free(tab[index].copy);
	}
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;

	tab = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (tab == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (tab[i].copy == NULL)
		{
			free_stock_str(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
