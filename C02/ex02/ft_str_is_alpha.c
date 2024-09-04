/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:00:49 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/09 17:54:22 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* this function to check for the object if is it an alph or not */
int	alpha_check(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(alpha_check(str[i])))
		{
			return (0);
		}
		i ++;
	}
	return (1);
}
