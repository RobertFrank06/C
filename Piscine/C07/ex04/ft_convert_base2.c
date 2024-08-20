/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:01:02 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/19 20:51:03 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*handle_zero_case(char *base);
char	*create_result_str(int nbr, int num_len, char *base);
char	*convert_to_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

char	*convert_to_base(int nbr, char *base)
{
	int	base_len;
	int	num_len;

	base_len = ft_strlen(base);
	num_len = calculate_num_len(nbr, base_len);
	return (create_result_str(nbr, num_len, base));
}

int	ft_atoi_base(char *str, char *base)
{
	int	value;
	int	endresult;
	int	minus;

	minus = 1;
	endresult = 0;
	if (!is_valid_base(base))
		return (0);
	str = skipwhitespaceandplus(str, &minus);
	while (*str)
	{
		value = char_to_value(*str, base);
		if (value == -1)
			return (0);
		endresult = endresult * ft_strlen(base) + value;
		str++;
	}
	return (minus * endresult);
}
