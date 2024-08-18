/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:32:22 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/14 20:10:31 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	first;
	int	last;
	int	guessedfactor;

	first = 2;
	last = nb / 2;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (first <= last)
	{
		guessedfactor = first + (last - first) / 2;
		if (nb % guessedfactor == 0)
			return (0);
		else if (guessedfactor * guessedfactor < nb)
			first = guessedfactor + 1;
		else
			last = guessedfactor - 1;
	}
	return (1);
}
