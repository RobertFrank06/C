/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:00:08 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/19 20:50:40 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		contains_bad_chars(char *base);
int		is_valid_base(char *base);
int		char_to_value(char c, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	contains_bad_chars(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_base(char *base)
{
	if (ft_strlen(base) < 2 || contains_bad_chars(base))
		return (0);
	return (1);
}

int	char_to_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;
	int		base_from_len;
	int		base_to_len;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	base_from_len = ft_strlen(base_from);
	base_to_len = ft_strlen(base_to);
	num = ft_atoi_base(nbr, base_from);
	result = convert_to_base(num, base_to);
	return (result);
}
