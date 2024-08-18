/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:14:40 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/18 16:50:52 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	argv++;
	while (*argv)
	{
		argc = ft_strlen(*argv);
		write(1, *argv, argc);
		write(1, "\n", 1);
		argv++;
	}
	return (0);
}