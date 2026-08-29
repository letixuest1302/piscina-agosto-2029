/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:36:04 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/18 10:36:33 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str [i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}
/*
int	 main(void)
{
	char	arr1[7] = "fuerte";
	char	arr2[7] = "espera";

	printf("%d\n", ft_str_is_alpha(arr1));
	printf("%d\n", ft_str_is_alpha(arr2));
	printf("%d\n", ft_str_is_alpha(""));
	return (0);
}*/
