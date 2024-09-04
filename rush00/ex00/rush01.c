/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:17:37 by amismail          #+#    #+#             */
/*   Updated: 2024/06/07 17:18:52 by amismail         ###   ########.fr       */
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
			if ((i == 1 && j == 1) || (i == y && j == x && i > 1 && j > 1))
				ft_putchar('/');
			else if ((i == y && j == 1 && i > 1) || (i == 1 && j == x))
				ft_putchar('\\');
			else if (j == 1 || j == x || i == 1 || i == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
			j ++;
		}
		ft_putchar('\n');
		i++;
	}
}
