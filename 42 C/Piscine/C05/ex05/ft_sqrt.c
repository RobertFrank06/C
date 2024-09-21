/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:20:22 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/14 19:29:59 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	first;
	int	last;
	int	guess;
	int	sqrt;

	sqrt = 0;
	first = 0;
	last = nb;
	if (nb <= 0)
		return (0);
	while (first <= last)
	{
		guess = first + (last - first) / 2;
		sqrt = guess * guess;
		if (sqrt == nb)
			return (guess);
		else if (sqrt < nb)
			first = guess + 1;
		else
			last = guess - 1;
	}
	return (0);
}
