/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:12 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/14 17:37:54 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	numbefore;

	numbefore = nb - 1;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (numbefore > 1)
	{
		nb *= numbefore;
		numbefore--;
	}
	return (nb);
}
