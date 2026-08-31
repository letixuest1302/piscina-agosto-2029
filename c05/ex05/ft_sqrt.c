/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:54:12 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/30 15:28:28 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	number;

	number = 1;
	if (nb > 0)
	{
		while (number * number < nb)
			number++;
		if (number * number == nb)
			return (number);
	}
	return (0);
}
/*
int	main(void)
{
	int	nb;

	printf("raiz cuadrda: ");
	scanf("%d", &nb);
	nb = ft_sqrt(nb);
	printf("resultado: %d", nb);
	return (0);
}*/
