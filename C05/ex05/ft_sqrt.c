/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:29:15 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/28 15:57:33 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*int	ft_sqrt(long int nb)
{
	float	counter;
	float	ans;

	counter = 1;
	if (nb == 0 || nb == 1)
		return (nb);
	while (counter <= nb / 2)
	{
		ans = nb / counter;
		if (ans == counter)
			return (ans);
		counter ++;
	}
	return (0);
}*/

int	ft_sqrt(int nb)
{
	int	counter;

	counter = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	while (counter * counter <= nb)
	{
		if (counter * counter == nb)
			return (counter);
		counter++;
	}
	return (0);
}
/*
int	main(void)
{
	int	i;

	i = ft_sqrt(100);
	printf ("%i\n", i);
}*/
