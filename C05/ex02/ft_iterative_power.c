/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:28:39 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/28 18:59:25 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	ans;

	ans = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power != 0)
	{
		ans *= nb;
		power --;
	}
	return (ans);
}
/*
int	main(void)
{
	int	i;

	i = ft_iterative_power(3, 1);
	printf("%i\n", i);
}
*/
