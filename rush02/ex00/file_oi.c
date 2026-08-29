/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_oi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:39:56 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:39:58 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	get_file_size(char *filename)
{
	int		fd;
	int		size;
	int		bytes_read;
	char	buf[1024];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	bytes_read = read(fd, buf, 1024);
	while (bytes_read > 0)
	{
		size += bytes_read;
		bytes_read = read(fd, buf, 1024);
	}
	close(fd);
	if (bytes_read < 0)
		return (-1);
	return (size);
}

static int	read_all(int fd, char *buffer, int size)
{
	int	total;
	int	got;

	total = 0;
	while (total < size)
	{
		got = read(fd, buffer + total, size - total);
		if (got <= 0)
			return (0);
		total += got;
	}
	return (1);
}

char	*read_file(char *filename)
{
	int		fd;
	int		size;
	char	*buffer;

	size = get_file_size(filename);
	if (size < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!read_all(fd, buffer, size))
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}
