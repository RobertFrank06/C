/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:38:14 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/11 21:49:36 by treineke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_input(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (i % 2)
		{
			if (argv[1][i] != ' ' && argv[1][i] != 0)
				return (0);
		}
		else
		{
			if (argv[1][i] < '1' || argv[1][i] > '4')
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}
