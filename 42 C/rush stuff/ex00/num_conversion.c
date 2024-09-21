/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:11:50 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/08/17 22:02:28 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_dict_entry
{
	char	*number_str;
	char	*text;
}			t_dict_entry;

char		*ft_strdup(const char *src);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);

const char	*find_in_dictionary(const t_dict_entry *dict, size_t size,
		const char *number)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].number_str, number) == 0)
			return (dict[i].text);
		i++;
	}
	return (NULL);
}

char	*handle_tens_and_lower(const char *number_str, const t_dict_entry *dict,
		size_t size)
{
	char		tens[3] = {number_str[0], '0', '\0'};
	const char	*dict_entry = find_in_dictionary(dict, size, tens);
	char		*result;

	result = ft_strdup(dict_entry);
	if (number_str[1] != '0')
	{
		result = append_strings(result, find_in_dictionary(dict, size,
					&number_str[1]));
	}
	return (result);
}

char	*handle_hundreds(const char *number_str, const t_dict_entry *dict,
		size_t size)
{
	char		hundreds[2] = {number_str[0], '\0'};
	const char	*dict_entry = find_in_dictionary(dict, size, hundreds);
	char		*result;
	char		remainder[3] = {number_str[1], number_str[2], '\0'};

	result = ft_strdup(dict_entry);
	result = append_strings(result, "hundred");
	if (ft_strcmp(remainder, "00") != 0)
	{
		result = append_strings(result, convert_number_to_words(remainder, dict,
					size));
	}
	return (result);
}

char	*handle_number_by_length(int len, const char *number_str,
		const t_dict_entry *dict, int size)
{
	if (len > 3 && len <= 6)
		return (handle_large_numbers(number_str, dict, size, 3));
	else if (len > 6 && len <= 9)
		return (handle_large_numbers(number_str, dict, size, 6));
	else if (len > 9 && len <= 12)
		return (handle_large_numbers(number_str, dict, size, 9));
	else if (len > 12 && len <= 15)
		return (handle_large_numbers(number_str, dict, size, 12));
	else if (len > 15 && len <= 18)
		return (handle_large_numbers(number_str, dict, size, 15));
	else if (len > 18 && len <= 21)
		return (handle_large_numbers(number_str, dict, size, 18));
	else if (len > 21 && len <= 24)
		return (handle_large_numbers(number_str, dict, size, 21));
	else if (len > 24 && len <= 27)
		return (handle_large_numbers(number_str, dict, size, 24));
	else if (len > 27 && len <= 30)
		return (handle_large_numbers(number_str, dict, size, 27));
	else if (len > 30 && len <= 33)
		return (handle_large_numbers(number_str, dict, size, 30));
	else if (len > 33 && len <= 36)
		return (handle_large_numbers(number_str, dict, size, 33));
	else if (len > 36 && len <= 39)
		return (handle_large_numbers(number_str, dict, size, 36));
}

static char	*convert_number_to_words(const char *number_str,
		const t_dict_entry *dict, int size)
{
	int	len;

	len = ft_strlen(number_str);
	if (len == 2)
		return (handle_tens_and_units(number_str, dict, size));
	else if (len == 3)
		return (handle_hundreds(number_str, dict, size));
	else
		return (handle_number_by_length(len, number_str, dict, size));
}
