/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:13:26 by joklein           #+#    #+#             */
/*   Updated: 2024/08/08 12:36:41 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	u;

	i = 0;
	u = 0;
	while (dest[i] != '\0')
		i++;
	while (src[u] != '\0' && u < nb)
	{
		dest[i] = src[u];
		i++;
		u++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char			*dest;
// 	char			*dest2;
// 	char			*src;
// 	char			a[99] = "Hello";
// 	char			b[99] = "Hello";
// 	char			c[] = "klopa";
// 	unsigned int	nb;

// 	nb = 5;
// 	dest = a;
// 	dest2 = b;
// 	src = c;
// 	printf("%s", strncat(dest2, src, nb));
// 	printf("%s", "\n");
// 	printf("%s", ft_strncat(dest, src, nb));
// 	return (0);
// }
