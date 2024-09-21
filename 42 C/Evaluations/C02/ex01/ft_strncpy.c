/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:36:39 by fkonig            #+#    #+#             */
/*   Updated: 2024/08/08 12:50:31 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*start;

	start = dest;
	while (n != 0)
	{
		if (*src == '\0')
			break ;
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n != 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (start);
}

// int main()
// {
// 	char a[3] = "123";
// 	char b[3] = "345";

// 	ft_strncpy(a ,b ,3);
// 	printf("%s", a);
// }