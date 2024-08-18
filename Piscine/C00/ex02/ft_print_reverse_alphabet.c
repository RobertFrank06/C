/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:31:11 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/01 00:34:09 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	abc[26];
	int		i;
	char	c;

	i = 0;
	c = 122;
	while (c > 96)
	{
		abc[i] = c;
		c--;
		i++;
	}
	write(1, &abc, 26);
}
