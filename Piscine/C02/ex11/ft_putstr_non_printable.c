/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:02:42 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/08 16:11:59 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	char_to_hex(int c)
{
	char	*hexsymbols;

	hexsymbols = "0123456789abcdef";
	c = hexsymbols[c];
	return (c);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex;

	i = 0;
	while (str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 127)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			hex = str[i] / 16;
			ft_putchar(char_to_hex(hex));
			hex = str[i] % 16;
			ft_putchar(char_to_hex(hex));
		}
		i++;
	}
}
