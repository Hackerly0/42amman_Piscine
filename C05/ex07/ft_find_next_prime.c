/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:29:46 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/26 13:29:48 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb > 2 && nb % 2 == 0)
		return (0);
	if (nb > 2 && nb % 2 != 0)
	{
		while (i < nb)
		{
			if (nb % i == 0)
				return (0);
			i = i + 2;
		}
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (i % 2 == 0)
		i ++;
	while (i)
	{
		if (ft_is_prime(i) == 1)
		{
			return (i);
		}
		i = i + 2;
	}
	return (0);
}
/*
int	main(void)
{
	int	k;

	k = ft_find_next_prime(14);
	printf("%i\n", k);
}*/
