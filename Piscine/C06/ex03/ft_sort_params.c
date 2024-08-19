/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:59:04 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/19 16:55:58 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_arguments(char **tab, int size)
{
	int		first;
	char	*tmp;
	int		loop;

	first = 0;
	loop = 0;
	while (loop < size - 1)
	{
		first = 0;
		while (first < size - loop - 1)
		{
			if (*(tab[first]) > *(tab[first + 1]))
			{
				tmp = tab[first];
				tab[first] = tab[first + 1];
				tab[first + 1] = tmp;
			}
			first++;
		}
		loop++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_arguments(argv + 1, argc - 1);
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
