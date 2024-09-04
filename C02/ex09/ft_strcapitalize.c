/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:48:31 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/10 20:01:41 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alph(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int	is_numb(char s)
{
	if (s >= '0' && s <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_upper(char u)
{
	if (u >= 'A' && u <= 'Z')
	{
		return (1);
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_upper(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	ft_strlowcase(str);
	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (new_word && is_alph(str[i]))
		{
			str[i] -= 32;
			new_word = 0;
		}
		if (!is_alph(str[i]) && !is_numb(str[i]))
		{
			new_word = 1;
		}
		else if (is_numb(str[i]))
		{
			new_word = 0;
		}
		i++;
	}
	return (str);
}
