/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:17:14 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/09 18:21:22 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* this function to check for the object if is it an lower or not */
int	lower_check(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(lower_check(str[i])))
		{
			return (0);
		}
		i ++;
	}
	return (1);
}
