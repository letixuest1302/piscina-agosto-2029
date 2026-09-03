/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:50:00 by lesainz           #+#    #+#             */
/*   Updated: 2026/09/02 12:50:05 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_atoi_rows(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (len <= 0)
		return (-1);
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

static int	validate_chars(t_map *map)
{
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	if (map->empty < 32 || map->empty > 126
		|| map->obstacle < 32 || map->obstacle > 126
		|| map->full < 32 || map->full > 126)
		return (0);
	return (1);
}

int	parse_header(int fd, t_map *map)
{
	char	buf[100];
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n' && i < 99)
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	if (c != '\n' || i < 4)
		return (0);
	map->full = buf[i - 1];
	map->obstacle = buf[i - 2];
	map->empty = buf[i - 3];
	if (!validate_chars(map))
		return (0);
	map->rows = ft_atoi_rows(buf, i - 3);
	if (map->rows <= 0)
		return (0);
	return (1);
}
