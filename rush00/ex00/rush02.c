/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:36:01 by amismail          #+#    #+#             */
/*   Updated: 2024/06/08 12:49:26 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if ((i == 1 && j == 1) || (i == 1 && j == x && j > 1))
				ft_putchar('A');
			else if ((i == y && j == x && i > 1)
				|| (i == y && j == 1 && i > 1))
				ft_putchar('C');
			else if (j == 1 || j == x || i == 1 || i == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			j ++;
		}
		ft_putchar('\n');
		i++;
	}
}
