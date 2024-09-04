/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassaf <amassaf@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:05:37 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/22 13:31:36 by amassaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	num_of_visible_box(int *arr)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > max_height)
		{
			max_height = arr[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_columns(int **grid, int **cons)
{
	int	temp_up[4];
	int	temp_down[4];
	int	c;
	int	r;

	c = 0;
	r = 0;
	while (c < 4)
	{
		r = 0;
		while (r < 4)
		{
			temp_up[r] = grid[r][c];
			temp_down[r] = grid[4 - 1 - r][c];
			r++;
		}
		if ((num_of_visible_box(temp_up) != cons[0][c]))
			return (0);
		if ((num_of_visible_box(temp_down) != cons[1][c]))
			return (0);
		c++;
	}
	return (1);
}

int	check_rows(int **grid, int **cons)
{
	int	temp_left[4];
	int	temp_right[4];
	int	c;
	int	r;

	c = 0;
	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			temp_left[c] = grid[r][c];
			temp_right[c] = grid[r][4 - 1 - c];
			c++;
		}
		if ((num_of_visible_box(temp_left) != cons[2][r]))
			return (0);
		if ((num_of_visible_box(temp_right) != cons[3][r]))
			return (0);
		r++;
	}
	return (1);
}

int	check_cons(int **grid, int **cons)
{
	return (check_columns(grid, cons) && check_rows(grid, cons));
}
