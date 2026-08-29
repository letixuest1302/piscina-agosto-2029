/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:51:31 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/14 10:30:54 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size / 2)
	{
		swap = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = swap;
		i ++;
	}
}
/*
int	main(void)
{
	int	tab[6] = {0, 1, 2, 3, 4, 5};
	int	size;
	int	i;

	i = 0;
	size 6;
	ft_rev_int_tab(tab, size);
	i = 0;

	while (i < size)
	{
		printf("%d", tab[i]);
		if (i < size -1)
		{
			printf(",")
		}
		i ++;
	}
}*/
