/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:24:05 by joklein           #+#    #+#             */
/*   Updated: 2024/08/07 17:32:25 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	u;
	int				h;

	i = 0;
	u = 0;
	while (dest[i] != '\0')
		i++;
	if (i >= size)
		return (*dest);
	h = i;
	while ((src[u] != '\0') && (u < size - h - 1))
	{
		dest[i] = src[u];
		i++;
		u++;
	}
	dest[i] = '\0';
	return (*dest);
}

// int	main(void)
// {
// 	char			*dest;
// 	char			*dest2;
// 	char			*src;
// 	unsigned int	size;
// 	char			c[99] = "klopapasdasdasdasd";
// 	char			d[99] = "klopapasdasdasdasd";
// 	char			e[] = "rollejasdhasdasdasdasd";

// 	dest = c;
// 	dest2 = d;
// 	src = e;
// 	size = 15;
// 	strlcat(dest2, src, size);
// 	printf("%s", dest2);
// 	printf("%c", '\n');
// 	ft_strlcat(dest, src, size);
// 	printf("%s", dest);
// 	return (0);
// }
