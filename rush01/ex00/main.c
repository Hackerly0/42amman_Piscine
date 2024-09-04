/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassaf <amassaf@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:42:57 by tabuayya          #+#    #+#             */
/*   Updated: 2024/06/22 13:15:09 by amassaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		error_handling(int argc, char **argv);
int		grid(int **grid);
void	print_grid(int **grid);
int		**atoi_input(char *str);
void	ft_putstr(char *str);
int		solve(int row, int col, int **grid, int **cons);

#define N 4

void	free_memory(int **arr, int **cons)
{
	int	i;

	i = 0;
	while (i < N)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	i = 0;
	while (i < N)
	{
		free (cons[i]);
		i++;
	}
	free (cons);
}

int	main(int argc, char **argv)
{
	int	i;
	int	**arr;
	int	**cons;

	if (!error_handling (argc, argv))
	{
		arr = (int **)malloc(4 * sizeof(int *));
		i = 0;
		while (i < 4)
		{
			arr[i] = (int *)malloc(4 * sizeof(int));
			i++;
		}
		grid (arr);
		cons = atoi_input(argv[1]);
		i = solve (0, 0, arr, cons);
		if (i)
			print_grid (arr);
		else
			ft_putstr ("Error\n");
		free_memory (arr, cons);
	}
}
