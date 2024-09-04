/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassaf <amassaf@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:19:15 by amassaf           #+#    #+#             */
/*   Updated: 2024/06/22 12:29:31 by amassaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_cons(int **grid, int **cons);
int	is_valid(int **grid, int row, int col, int num);

int	solve(int row, int col, int **grid, int **cons)
{
	int	i;

	if (row == 4)
	{
		return (check_cons(grid, cons));
	}
	if (col == 4)
	{
		return (solve(row + 1, 0, grid, cons));
	}
	i = 1;
	while (i <= 4)
	{
		if (is_valid(grid, row, col, i))
		{
			grid[row][col] = i;
			if (solve(row, col + 1, grid, cons))
			{
				return (1);
			}
			grid[row][col] = 0;
		}
		i++;
	}
	return (0);
}
