/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 13:48:29 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/30 15:28:53 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	number;

	number = 2;
	if (nb < 2)
		return (0);
	while (number <= nb / 2)
	{
		if (nb % number == 0)
			return (0);
		number++;
	}
	return (1);
}
/*
int	main(void)
{
	int	nb;

	nb = 0;
	printf ("pon numero para probar");
	scanf("%d", &nb);
	nb = ft_is_prime (nb);
	if (nb == 0)
		printf("1\n");
	else
		printf("0\n");
	return (0);
}*/
