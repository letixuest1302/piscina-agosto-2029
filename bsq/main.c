/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:49:12 by lesainz           #+#    #+#             */
/*   Updated: 2026/09/02 12:49:16 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map_error(void)
{
	write(2, "map error\n", 10);
}

static void	process_stream(int fd)
{
	t_map	map;

	map.grid = NULL;
	if (!parse_header(fd, &map) || !parse_grid(fd, &map))
	{
		print_map_error();
		free_map(&map);
		return ;
	}
	solve_bsq(&map);
	print_solution(&map);
	free_map(&map);
}

static void	process_files(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			print_map_error();
		else
		{
			process_stream(fd);
			close(fd);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		process_stream(0);
	else
		process_files(argc, argv);
	return (0);
}
