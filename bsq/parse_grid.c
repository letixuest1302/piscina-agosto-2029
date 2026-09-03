/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:49:30 by lesainz           #+#    #+#             */
/*   Updated: 2026/09/02 12:56:36 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	allocate_grid(t_map *map)
{
	int	i;

	map->grid = (int **)malloc(sizeof(int *) * map->rows);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = (int *)malloc(sizeof(int) * map->cols);
		if (!map->grid[i])
			return (0);
		i++;
	}
	return (1);
}

static int	read_first_line(int fd, t_map *map, char **first_buf)
{
	char	c;
	int		cols;
	int		cap;

	cols = 0;
	cap = 1024;
	*first_buf = (char *)malloc(sizeof(char) * cap);
	if (!*first_buf)
		return (0);
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (cols >= cap - 1)
			return (0);
		(*first_buf)[cols] = c;
		cols++;
	}
	if (cols == 0)
		return (0);
	map->cols = cols;
	return (1);
}

static int	store_line(t_map *map, int r, char *buf)
{
	int	c;

	c = 0;
	while (c < map->cols)
	{
		if (buf[c] == map->empty)
			map->grid[r][c] = 1;
		else if (buf[c] == map->obstacle)
			map->grid[r][c] = 0;
		else
			return (0);
		c++;
	}
	return (1);
}

static int	read_rest_lines(int fd, t_map *map)
{
	char	c;
	int		r;
	int		c_idx;

	r = 1;
	while (r < map->rows)
	{
		c_idx = 0;
		while (read(fd, &c, 1) > 0 && c != '\n')
		{
			if (c_idx >= map->cols)
				return (0);
			if (c == map->empty)
				map->grid[r][c_idx] = 1;
			else if (c == map->obstacle)
				map->grid[r][c_idx] = 0;
			else
				return (0);
			c_idx++;
		}
		if (c_idx != map->cols)
			return (0);
		r++;
	}
	return (1);
}

int	parse_grid(int fd, t_map *map)
{
	char	*first_buf;
	char	extra;

	first_buf = NULL;
	if (!read_first_line(fd, map, &first_buf))
	{
		if (first_buf)
			free(first_buf);
		return (0);
	}
	if (!allocate_grid(map) || !store_line(map, 0, first_buf))
	{
		free(first_buf);
		return (0);
	}
	free(first_buf);
	if (!read_rest_lines(fd, map))
		return (0);
	if (read(fd, &extra, 1) > 0)
		return (0);
	return (1);
}
