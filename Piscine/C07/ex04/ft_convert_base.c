/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:00:08 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/19 20:26:14 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*convert_to_base(int nbr, char *base);
int		ft_strlen(char *str);

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	value;
	int	sign;
	int	base_len;

	value = 0;
	sign = 1;
	if (!is_valid_base(base))
		return (0);
	while (*str <= 32 || *str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	base_len = ft_strlen(base);
	while (*str && char_to_value(*str, base) != -1)
	{
		value = value * base_len + char_to_value(*str, base);
		str++;
	}
	return (value * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num_in_base10;
	char	*result;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	num_in_base10 = ft_atoi_base(nbr, base_from);
	result = convert_to_base(num_in_base10, base_to);
	return (result);
}

char	*convert_to_base(int nbr, char *base)
{
	int	base_len;
	int	num_len;

	base_len = ft_strlen(base);
	num_len = calculate_num_len(nbr, base_len);
	return (create_result_str(nbr, num_len, base));
}
