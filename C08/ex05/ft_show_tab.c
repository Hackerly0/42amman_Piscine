/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salshaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:09 by salshaha          #+#    #+#             */
/*   Updated: 2024/07/02 17:30:11 by salshaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
/*
int main()
{
	printf("%d\n", ABS(42));
	printf("%d\n", ABS(-42));
	printf("%d\n", ABS(30 - 42));
	printf("%d\n", ABS(50 * -45));
	printf("%d\n", ABS(-24) - 20);
	printf("--------------------\n");
	char **a = (char**)malloc(sizeof(char*) * 3);
	a[0] = (char*)malloc(sizeof(char) * 1024);
	a[1] = (char*)malloc(sizeof(char) * 1024);
	a[2] = (char*)malloc(sizeof(char) * 1024);
	strcpy(a[0], "ieSrBXBI5d4rW9O2");
	strcpy(a[1], "eadLhPjehRMwjqv9JJ7Q0WiLTBoVxsLx");
	strcpy(a[2], "MKynFC5rJwCJ0jdD");
	t_stock_str *b = ft_strs_to_tab(3, a);
	for (int i = 0; b[i].str != 0; i++)
		printf("%s \n%s | %d\n", b[i].str, b[i].copy, b[i].size);
	b[0].copy = "bafj";
	ft_show_tab(b);
	for (int i = 0; b[i].str != 0; i++)
		free(b[i].copy);
	free(b);
	free(a[0]);
	free(a[1]);
	free(a[2]);
	free(a);
	return 0;
}*/
