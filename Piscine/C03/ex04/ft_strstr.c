/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:35:33 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 13:55:17 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*strng;
	char	*substrng;

	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		strng = str;
		substrng = to_find;
		while (*strng && *substrng && (*strng == *substrng))
		{
			strng++;
			substrng++;
		}
		if (*substrng == '\0')
		{
			return (str);
		}
		str++;
	}
	return ((char *)0);
}
