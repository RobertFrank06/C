/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:19:54 by joklein           #+#    #+#             */
/*   Updated: 2024/08/07 11:27:17 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (dest[i] != '\0')
		i++;
	while (src[u] != '\0')
	{
		dest[i] = src[u];
		i++;
		u++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	*dest;
// 	char	*dest2;
// 	char	*src;
// 	char	a[99] = "Hello";
// 	char	b[99] = "Hello";
// 	char	c[] = "klo";

// 	dest = a;
// 	dest2 = b;
// 	src = c;
// 	printf("%s", strcat(dest2, src));
// 	printf("%s", "\n");
// 	printf("%s", ft_strcat(dest, src));
// 	return (0);
// }
