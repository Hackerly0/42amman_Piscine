/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:29:33 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/26 13:30:37 by hnisirat         ###   ########.fr       */
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

/*int	main(void)
{
	int	j;

	j = ft_is_prime(12);
	printf("%i\n", j);
}
*/
