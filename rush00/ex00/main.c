/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henarmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:36:24 by henarmar          #+#    #+#             */
/*   Updated: 2026/08/16 18:16:44 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	rush00(int tot_col, int tot_row);
void	rush01(int tot_col, int tot_row);
void	rush02(int tot_col, int tot_row);
void	rush03(int tot_col, int tot_row);
void	rush04(int tot_col, int tot_row);

int	main(void)
{
	int	wanted_rush;

	wanted_rush = 2;
	if (wanted_rush == 0)
	{
		rush00(3, 5);
	}
	else if (wanted_rush == 1)
	{
		rush01(3, 3);
	}
	else if (wanted_rush == 2)
	{
		rush02(5, 3);
	}
	else if (wanted_rush == 3)
	{
		rush03(4, 4);
	}
	else if (wanted_rush == 4)
	{
		rush04(6, 6);
	}
	return (0);
}
