/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:05:08 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/23 17:04:03 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size <= i)
		return (size + j);
	while (src[k] != '\0' && i + k < size - 1)
	{
		dest[i + k] = src[k];
		k++;
	}
	if (i + k < size)
		dest[i + k] = '\0';
	return (i + j);
}
