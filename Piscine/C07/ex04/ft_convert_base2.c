/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:01:02 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/19 20:26:01 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		calculate_num_len(int nbr, int base_len);
char	*handle_zero_case(char *base);
char	*create_result_str(int nbr, int num_len, char *base);
char	*convert_to_base(int nbr, char *base);
int		char_to_value(char c, char *base);

int	char_to_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	calculate_num_len(int nbr, int base_len)
{
	int		num_len;
	long	tmp_nbr;

	num_len = 0;
	tmp_nbr = nbr;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		num_len++;
	while (tmp_nbr != 0)
	{
		num_len++;
		tmp_nbr /= base_len;
	}
	return (num_len);
}

char	*handle_zero_case(char *base)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = base[0];
	result[1] = '\0';
	return (result);
}

char	*create_result_str(int nbr, int num_len, char *base)
{
	char	*result;
	long	tmp_nbr;
	int		base_len;

	if (nbr == 0)
		return (handle_zero_case(base));
	base_len = ft_strlen(base);
	result = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	if (nbr < 0)
		tmp_nbr = -(long)nbr;
	else
		tmp_nbr = nbr;
	while (num_len--)
	{
		result[num_len] = base[tmp_nbr % base_len];
		tmp_nbr /= base_len;
	}
	if (nbr < 0)
		result[0] = '-';
	return (result);
}
