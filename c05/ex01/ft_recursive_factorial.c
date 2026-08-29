/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:51:14 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/27 17:23:33 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_factorial(int nb)
{
	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

int	main(void)
{
	int	test_nb1 = 1;
	int	test_nb2 = 0;
	int	test_nb3 = -13;
	int	test_nb4 = 5;
	int	test_nb5 = 13;
	
	printf("Resultado para 1: %d\n", ft_recursive_factorial(test_nb1));
	printf("Resultado para 0: %d\n", ft_recursive_factorial(test_nb2));
	printf("Resultado para -13: %d\n", ft_recursive_factorial(test_nb3));
	printf("Resultado para 5: %d\n", ft_recursive_factorial(test_nb4));
	printf("Resultado para 13: %d\n", ft_recursive_factorial(test_nb5));
	return (0);
}