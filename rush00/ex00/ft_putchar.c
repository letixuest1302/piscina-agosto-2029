/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henarmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:39:56 by henarmar          #+#    #+#             */
/*   Updated: 2026/08/16 15:27:57 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function to write characters */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	put_row(int tot_col, char first_col, char between_col, char last_col)
{
	int	col_counter;

	col_counter = 0;
	while (col_counter < tot_col)
	{
		if (col_counter == 0)
		{
			ft_putchar(first_col);
		}
		else if (col_counter == tot_col - 1)
		{
			ft_putchar(last_col);
		}
		else
		{
			ft_putchar(between_col);
		}
		col_counter++;
	}
	ft_putchar('\n');
}
