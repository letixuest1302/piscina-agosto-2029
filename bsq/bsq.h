/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:48:59 by lesainz           #+#    #+#             */
/*   Updated: 2026/09/02 12:52:13 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 32768

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	int		**grid;
	int		max_size;
	int		max_r;
	int		max_c;
}	t_map;

int		parse_header(int fd, t_map *map);
int		parse_grid(int fd, t_map *map);
void	solve_bsq(t_map *map);
void	print_solution(t_map *map);
void	free_map(t_map *map);
void	print_map_error(void);

#endif
