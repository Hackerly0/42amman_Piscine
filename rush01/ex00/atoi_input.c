/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassaf <amassaf@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:42:51 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/21 19:29:35 by amassaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);

int	**create_arr(void)
{
	int	i;
	int	**cons;

	cons = (int **)malloc(4 * sizeof(int *));
	i = 0;
	while (i < 4)
	{
		cons[i] = (int *) malloc(4 * sizeof(int));
		i++;
	}
	return (cons);
}

int	**atoi_input(char *str)
{
	int	**cons;
	int	i;
	int	j;
	int	r;
	int	c;

	cons = create_arr();
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && str[i] != ' ')
		{
			r = j / 4;
			c = j % 4;
			cons[r][c] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (cons);
}
