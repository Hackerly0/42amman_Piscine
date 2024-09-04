/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassaf <amassaf@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:32:15 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/22 13:19:52 by amassaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

int	error_handling(int argc, char **argv)
{
	int	j;

	j = 0;
	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	if (ft_strlen(argv[1]) != 31)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	while (argv[1][j] != '\0')
	{
		if ((argv[1][j] < '1' || argv[1][j] > '4') && argv[1][j] != ' ')
		{
			write (1, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}
