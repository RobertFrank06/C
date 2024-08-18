/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:47:16 by joklein           #+#    #+#             */
/*   Updated: 2024/08/07 10:07:51 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' && s2[i] != '\0')
		return (0);
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	str1[] = "Hello";
// 	char	str2[] = "Hello";
// 	s1 = str1;
// 	s2 = str2;
// 	printf("%d", strcmp(s1, s2));
// 	printf("%s", "\n");
// 	printf("%d", ft_strcmp(s1, s2));
// 	return (0);
// }
