/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:50:20 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/22 16:34:55 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' )
	{
		i ++;
	}
	while (src[j] != '\0' && nb > 0)
	{
		dest[i] = src[j];
		j ++;
		i ++;
		nb --;
	}
	dest[i] = '\0';
	return (dest);
}
