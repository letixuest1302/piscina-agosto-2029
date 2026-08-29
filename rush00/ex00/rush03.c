/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henarmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:35:06 by henarmar          #+#    #+#             */
/*   Updated: 2026/08/16 17:42:16 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c);

void	put_row(int tot_col, char first_col, char between_col, char last_col);

/*Program to write each row to draw the figure */
int	rush03(int tot_col, int tot_row)
{
	int	row_now;

	row_now = 0;
	if (tot_col <= 0 || tot_row <= 0)
	{
		return (0);
	}
	while (row_now < tot_row)
	{
		if (row_now == 0)
		{
			put_row(tot_col, 'A', 'B', 'C');
		}
		else if (row_now == tot_row - 1)
		{
			put_row(tot_col, 'A', 'B', 'C');
		}
		else
		{
			put_row(tot_col, 'B', ' ', 'B');
		}
		row_now++;
	}
	return (0);
}
