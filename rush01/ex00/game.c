/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicsanch <vicsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:04:42 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/23 17:32:34 by vicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		validator(char *str);
int		can_place(int grid[4][4], int row, int col, int num);
int		solve(int grid[4][4], int *clues, int pos);
int		check_cols(int grid[4][4], int *clues);
int		check_rows(int grid[4][4], int *clues);
int		is_valid_solution(int grid[4][4], int *clues);
int		count_visible(int *arr);
void	parse_int(char *str, int *clues, int grid[4][4]);
void	print_board(int grid[4][4]);

void	print_board(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[16];

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (validator(argv[1]) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	parse_int(argv[1], clues, grid);
	if (solve(grid, clues, 0))
		print_board(grid);
	else
		write(2, "Error\n", 6);
	return (0);
}
