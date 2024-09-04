/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:17:41 by hnisirat          #+#    #+#             */
/*   Updated: 2024/07/02 16:33:28 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*make_str(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len = len + str_len(strs[i]);
		i++;
	}
	len = len + str_len(sep) * (size - 1);
	if (size <= 0)
		len = 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = make_str(size, strs, sep);
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
		{
			str[k++] = sep[j];
			j++;
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}
/*
int	main ()
{
	char *v[] = { "Haitham" , "Nisirat" };
	char sep[] = " ";
	char *total = ft_strjoin(2, v, sep);
	if (total != NULL)
	{
		printf("%s", total);
		free (total);
	}
}*/
