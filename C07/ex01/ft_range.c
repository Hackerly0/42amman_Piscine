/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:04:47 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/30 13:26:45 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	i = 0;
	if (min == max || min > max)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
		return (NULL);
	while (max > min)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
/*
int	main(void)
{
	int i;

	i = 0;
	while (i < 17)
	{
	printf("%d\n", ft_range(3, 20)[i]);
	i++;
	}
	return (0);
}*/
