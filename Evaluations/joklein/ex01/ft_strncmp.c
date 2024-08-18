/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:13:26 by joklein           #+#    #+#             */
/*   Updated: 2024/08/07 10:28:56 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
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
//     unsigned int n;
// 	char	str1[] = "Hello";
// 	char	str2[] = "Helo";
//     n = 3;
// 	s1 = str1;
// 	s2 = str2;
// 	printf("%d", strncmp(s1, s2, n));
// 	printf("%s", "\n");
// 	printf("%d", ft_strncmp(s1, s2, n));
// 	return (0);
// }
