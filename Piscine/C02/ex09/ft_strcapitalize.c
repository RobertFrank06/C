/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:45:35 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/05 18:41:16 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first_letter_capital;

	i = 0;
	first_letter_capital = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z' && first_letter_capital == 0)
		{
			str[i] = str[i] - 32;
			first_letter_capital = 1;
		}
		else if ('A' <= str[i] && str[i] <= 'Z' && first_letter_capital == 1)
			str[i] = str[i] + 32;
		else if (!('A' <= str[i] && str[i] <= 'Z') && !('a' <= str[i]
				&& str[i] <= 'z') && !('0' <= str[i] && str[i] <= '9'))
			first_letter_capital = 0;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			first_letter_capital = 1;
		else if ('0' <= str[i] && str[i] <= '9')
			first_letter_capital = 1;
		i++;
	}
	return (str);
}
