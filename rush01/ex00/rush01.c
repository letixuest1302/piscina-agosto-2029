/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicsanch <vicsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 14:49:20 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/23 17:48:11 by vicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validator(char *str);
int		can_place(int grid[4][4], int row, int col, int num);
int		solve(int grid[4][4], int *clues, int pos);
int		check_cols(int grid[4][4], int *clues);
int		check_rows(int grid[4][4], int *clues);
int		is_valid_solution(int grid[4][4], int *clues);
int		count_visible(int *arr);

void	parse_int(char *str, int *clues, int grid[4][4]);
void	print_board(int grid[4][4]);

int	validator(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		i++;
	}
	return (i == 31);
}

void	parse_int(char *str, int *clues, int grid[4][4])
{
	int	i;
	int	count;
	int	number;

	i = 0;
	count = 0;
	while (str[i] != '\0' && count < 16)
	{
		if (str[i] != ' ')
		{
			number = str[i] - '0';
			clues[count] = number;
			grid[count / 4][count % 4] = 0;
			count++;
		}
		i++;
	}
}

int	can_place(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[4][4], int *clues, int pos)
{
	int	num;
	int	row;
	int	col;

	if (pos == 16)
		return (is_valid_solution(grid, clues));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (can_place(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
