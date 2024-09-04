/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:10:04 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/30 17:36:04 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	return (s1[i] - s2[i]);
}

int	print(int g, char **c)
{
	int	i;
	int	j;

	i = 1;
	while (i < g)
	{
		j = 0;
		while (c[i][j])
		{
			write(1, &c[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*c;

	c = NULL;
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				c = argv[i];
				argv[i] = argv[j];
				argv[j] = c;
			}
			j ++;
		}
		i++;
	}
	print(argc, argv);
	return (0);
}
