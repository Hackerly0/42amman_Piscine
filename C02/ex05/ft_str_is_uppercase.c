/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:19:26 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/09 18:21:35 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* this function to check for the object if is it an upper or not */
int	upper_check(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(upper_check(str[i])))
		{
			return (0);
		}
		i ++;
	}
	return (1);
}
