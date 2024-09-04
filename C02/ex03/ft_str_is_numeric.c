/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:03:37 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/09 18:20:59 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/* this function to check for the object if is it an num or not */
int	num_check(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(num_check(str[i])))
		{
			return (0);
		}
		i ++;
	}
	return (1);
}
