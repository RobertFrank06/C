/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <rfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:28:36 by rfrank            #+#    #+#             */
/*   Updated: 2024/08/03 16:43:59 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		g_xrows;
int		g_ycolumns;

void	rush(int x, int y)
{
	g_xrows = 1;
	g_ycolumns = 1;
	while (y >= g_ycolumns)
	{
		while (x >= g_xrows)
		{
			if ((g_xrows == 1 && g_ycolumns == 1) || (g_ycolumns == y
					&& g_xrows == x && g_ycolumns != 1 && g_xrows != 1))
				ft_putchar('A');
			else if ((g_xrows == x && g_ycolumns == 1) || (g_ycolumns == y
					&& g_xrows == 1))
				ft_putchar('C');
			else if ((g_ycolumns == 1 && g_xrows != x) || (g_ycolumns != 1
					&& g_xrows == x) || (g_xrows == 1 || g_ycolumns == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
			g_xrows++;
		}
		g_xrows = 1;
		ft_putchar('\n');
		g_ycolumns++;
	}
}
