/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:51:43 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/27 17:19:41 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while(power > 0)
	{
		result *= nb;
		power --;
	}
	return (result);
}
int	main(void)
{
	int	base = 1;
	int	exponente = 3;
	int	resultado = ft_iterative_power(base, exponente);
	
	printf("%d elemento a %d es %d\n", base, exponente, resultado);
	return (0);
}