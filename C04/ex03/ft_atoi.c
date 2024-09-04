/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:58:15 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/26 10:58:33 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	nega_sign(char n)
{
	if (n == '-')
		return (1);
	else if (n == '+')
		return (0);
	return (0);
}

int	ft_atoi(char *str)
{
	int	index;
	int	r;
	int	si;

	index = 0;
	r = 0;
	si = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n'
		|| str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
	{
		index++;
	}
	while (str[index] == '-' || str[index] == '+')
	{
		si += nega_sign(str[index]);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		r = r * 10 + (str[index] - '0');
		index++;
	}
	if (si % 2 != 0)
		r = r * -1;
	return (r);
}
