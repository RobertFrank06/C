/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:53:36 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/13 17:37:03 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	char_to_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*skipwhitespaceandplus(char *str, int *minus)
{
	*minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus = -1;
		if (*str == '-' || *str == '+')
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
			str++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	containsbadstuff(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < ft_strlen(base))
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (1);
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	value;
	int	endresult;
	int	minus;

	minus = 1;
	endresult = 0;
	if (ft_strlen(base) < 2 || containsbadstuff(base))
		return (0);
	str = skipwhitespaceandplus(str, &minus);
	while (*str)
	{
		value = char_to_value(*str, base);
		if (value == -1)
			return (0);
		endresult = endresult * ft_strlen(base) + value;
		str++;
	}
	return (minus * endresult);
}
