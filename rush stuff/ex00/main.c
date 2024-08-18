/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:38:16 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/08/17 16:50:44 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	char *input_num;
	struct ??? new_ref_dict; // cal crear l'estructura i posar-li nom

	if (is_error(argc != 2 && argc != 3))
		return ("Error\n");
	if (iserror(atoi(argv[argc - 1]) < 1))
		return ("Error\n");
	input_num = argv[argc - 1];
	if (argc == 2)
		new_ref_dict = argv[1];
	convert_num_to_letter(atoi(argv[argc - 1]));
	return (0);
	//what if more arguments are given?

	//free malloc!
}

int	is_error(int error)
{
	if (error = 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

long	ft_atoi(char *str)
{
	long	i;
	long	num;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
