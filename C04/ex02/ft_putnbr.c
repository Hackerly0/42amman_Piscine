/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:34:34 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/26 15:45:17 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char memo)
{
	write(1, &memo, 1);
}

void	ft_putnbr(int nb)
{
	char	int_size[12];
	int		i;
	int		negative;

	i = 0;
	negative = 0;
	if (nb == 0)
		return ((void)ft_putchar('0'));
	if (nb < 0)
	{
		if (nb == -2147483648)
			return ((void)write(1, "-2147483648", 11));
		negative = 1;
		nb = -nb;
	}
	while (nb)
	{
		int_size[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (negative)
		int_size[i++] = '-';
	while (i--)
		ft_putchar(int_size[i]);
}
/*
int	main(void)
{
	ft_putnbr(42);
	return (0);
}*/
