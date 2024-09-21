/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:11:50 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/08/17 22:49:46 by rfrank           ###   ########.fr       */
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
char		*append_strings(const char *str1, const char *str2);

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
		int size)
{
	char	tens[3];
	char	units[2];
	char	*tens_str;
	char	*units_str;
	char	*result;

	tens[0] = number_str[0];
	tens[1] = '0';
	tens[2] = '\0';
	units[0] = number_str[1];
	units[1] = '\0';
	tens_str = find_in_dictionary(dict, size, atoi(tens));
	if (!tens_str)
		return (my_strdup("Error"));
	if (units[0] == '0')
		result = create_modifiable_string(tens_str);
	else
	{
		units_str = find_in_dictionary(dict, size, atoi(units));
		if (!units_str)
		{
			free(tens_str);
			return (my_strdup("Error"));
		}
		result = append_strings(tens_str, " ");
		result = append_strings(result, units_str);
		free(units_str);
	}
	free(tens_str);
	return (result);
}

char	*handle_hundreds(const char *number_str, const t_dict_entry *dict,
		size_t size)
{
	char		hundreds[2];
	char		remainder[3];
	const char	*dict_entry;
	char		*result;
	char		*remainder_words;

	hundreds[0] = number_str[0];
	hundreds[1] = '\0';
	remainder[0] = number_str[1];
	remainder[1] = number_str[2];
	remainder[2] = '\0';
	dict_entry = find_in_dictionary(dict, size, atoi(hundreds));
	result = ft_strdup(dict_entry);
	result = append_strings(result, "hundred");
	if (ft_strcmp(remainder, "00") != 0)
	{
		remainder_words = convert_number_to_words(remainder, dict, size);
		result = append_strings(result, remainder_words);
		free(remainder_words);
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
		return (handle_tens_and_lower(number_str, dict, size));
	else if (len == 3)
		return (handle_hundreds(number_str, dict, size));
	else
		return (handle_number_by_length(len, number_str, dict, size));
}
