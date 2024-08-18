/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:19:12 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/14 17:35:11 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nb1;

	nb1 = nb;
	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
		return (0);
	while (power > 1)
	{
		nb *= nb1;
		power--;
	}
	return (nb);
}
