/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:38:36 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/30 16:02:16 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		result *= nb;
		nb --;
	}
	return (result);
}
/*
int	main(void)
{
	printf("Factorial de -1 = %d\n", ft_iterative_factorial((-1));
	printf("Factorial de 0 = %d\n", ft_iterative_factorial((-0));
	printf("Factorial de 5 = %d\n", ft_iterative_factorial((5));
	printf("Factorial de 1 = %d\n", ft_iterative_factorial((1));
}*/
