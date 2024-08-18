/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:24:15 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/14 17:49:50 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	numbefore;

	numbefore = nb - 1;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
