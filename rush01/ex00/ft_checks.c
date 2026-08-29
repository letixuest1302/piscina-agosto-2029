/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicsanch <vicsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 13:45:36 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/23 17:33:24 by vicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validator(char *str);
int		can_place(int grid[4][4], int row, int col, int num);
int		solve(int grid[4][4], int *clues, int pos);
int		check_cols(int grid[4][4], int *clues);
int		check_rows(int grid[4][4], int *clues);
int		is_valid_solution(int grid[4][4], int *clues);
int		count_visible(int *arr);
void	print_board(int grid[4][4]);
void	parse_int(char *str, int *clues, int grid[4][4]);

int	count_visible(int *arr)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < 4)
	{
		if (arr[i] > max)
		{
			count++;
			max = arr[i];
		}
		i++;
	}
	return (count);
}

int	check_cols(int grid[4][4], int *clues)
{
	int	i;
	int	up[4];
	int	down[4];

	i = 0;
	while (i < 4)
	{
		up[0] = grid[0][i];
		up[1] = grid[1][i];
		up[2] = grid[2][i];
		up[3] = grid[3][i];
		down[0] = grid[3][i];
		down[1] = grid[2][i];
		down[2] = grid[1][i];
		down[3] = grid[0][i];
		if (count_visible(up) != clues[i]
			|| count_visible(down) != clues[i + 4])
			return (0);
		i++;
	}
	return (1);
}

int	check_rows(int grid[4][4], int *clues)
{
	int	i;
	int	left[4];
	int	right[4];

	i = 0;
	while (i < 4)
	{
		left[0] = grid[i][0];
		left[1] = grid[i][1];
		left[2] = grid[i][2];
		left[3] = grid[i][3];
		right[0] = grid[i][3];
		right[1] = grid[i][2];
		right[2] = grid[i][1];
		right[3] = grid[i][0];
		if (count_visible(left) != clues[i + 8])
			return (0);
		if (count_visible(right) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_solution(int grid[4][4], int *clues)
{
	if (!check_cols(grid, clues))
		return (0);
	if (!check_rows(grid, clues))
		return (0);
	return (1);
}
