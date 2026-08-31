/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:52:10 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/30 16:03:39 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 1)
		return (nb);
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
/*
int	main(void)
{
	int	nb;
	int	power;
	int	result;

	nb = 3;
	power = 5;
	printf("numero base: \n");
	printf("%d\n", nb);
	printf("exponente: \n");
	printf("%d\n", power);
	result = ft_recursive_power(nb, power);
	printf("resultado es: %d", result);
	return (0);
}*/
