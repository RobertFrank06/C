/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:53:15 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/13 15:52:24 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselength;

	baselength = ft_strlen(base);
	if (baselength > 1 && containsbadstuff(base) == 0)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putnbr_base(-(nbr / baselength), base);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= baselength)
			ft_putnbr_base(nbr / baselength, base);
		ft_putchar(base[nbr % baselength]);
	}
}
