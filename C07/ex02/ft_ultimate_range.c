/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:04:22 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/30 13:04:30 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*str;
	int	i;

	i = 0;
	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	str = (int *)malloc(size * sizeof(int));
	if (str == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (i < size)
	{
		str[i] = i + min;
		i++;
	}
	*range = str;
	return (size);
}
/*
int	main(void)
{
	int	*range;
	int	size;

	size = ft_ultimate_range(&range, 6, 10);
	for (int i = 0; i < size; i++)
        {
            printf("%i\n", range[i]);
        }
        free(range);
}*/
