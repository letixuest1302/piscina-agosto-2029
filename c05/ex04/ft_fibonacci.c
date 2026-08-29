/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:53:26 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/27 17:41:25 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (- 1);
	if (index == 0)
		return ( 0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
int main(void)
{
	int index;
	int	result;
	
	index = 0;
	printf ("Index: ");
	scanf ("%d", &index);
	result = ft_fibonacci(index);
	printf("F(%d) = %d\n", index, result);
}