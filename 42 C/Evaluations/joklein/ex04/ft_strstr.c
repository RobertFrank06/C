/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:49:54 by joklein           #+#    #+#             */
/*   Updated: 2024/08/08 12:37:03 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	h;
	int	u;

	i = 0;
	if (to_find[0] == '\0')
		return (&str[0]);
	while (str[i] != '\0')
	{
		h = i;
		u = 0;
		while (str[h] == to_find[u])
		{
			if (to_find[u + 1] == '\0')
				return (&str[i]);
			h++;
			u++;
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*str2;
// 	char	*to_find;
// 	char	c[] = "klpaopapier";
// 	char	d[] = "klpaopapier";
// 	char	e[] = "";

// 	str = c;
// 	str2 = d;
// 	to_find = e;
// 	printf("%s", strstr(str2, to_find));
// 	printf("%c", '\n');
// 	printf("%s", ft_strstr(str, to_find));
// 	return (0);
// }
