/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:50:16 by lesainz           #+#    #+#             */
/*   Updated: 2026/09/02 12:50:19 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	min3(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	solve_bsq(t_map *map)
{
	int	r;
	int	c;

	map->max_size = 0;
	map->max_r = 0;
	map->max_c = 0;
	r = -1;
	while (++r < map->rows)
	{
		c = -1;
		while (++c < map->cols)
		{
			if (map->grid[r][c] == 1 && r > 0 && c > 0)
				map->grid[r][c] = 1 + min3(map->grid[r - 1][c],
						map->grid[r][c - 1], map->grid[r - 1][c - 1]);
			if (map->grid[r][c] > map->max_size)
			{
				map->max_size = map->grid[r][c];
				map->max_r = r;
				map->max_c = c;
			}
		}
	}
}

void	print_solution(t_map *map)
{
	int		r;
	int		c;
	char	out;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->cols)
		{
			if (r > map->max_r - map->max_size && r <= map->max_r
				&& c > map->max_c - map->max_size && c <= map->max_c)
				out = map->full;
			else if (map->grid[r][c] == 0)
				out = map->obstacle;
			else
				out = map->empty;
			write(1, &out, 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}
