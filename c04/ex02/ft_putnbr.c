/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:41:10 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/24 12:21:46 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(-(INT_MIN + 2000000000));
	}
	else if (nb < 0)
	{
		ft_putchar ('-');
		ft_putnbr (-nb);
	}
	else if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr (nb / 10);
		ft_putchar ((nb % 10) + '0');
	}
}
/*
int	main(void)
{
	ft_putnbr(42);
	ft_putchar('\n');
	
	ft_putnbr(0);
	ft_putchar('\n');
	
	ft_putnbr(98765);
	ft_putchar('\n');
	
	ft_putnbr(-123);
	ft_putchar('\n');
	
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	
	ft_putnbr(INT_MIN);
	ft_putchar('\n');
	
	return 0;
}*/
