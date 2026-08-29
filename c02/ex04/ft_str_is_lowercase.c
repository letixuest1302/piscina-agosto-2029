/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:52:35 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/17 11:13:14 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	arr1[5] = "sdfgh";
	char	arr2[5] = "ApeL";

	printf("%d\n", ft_str_is_lowercase(arr1));
	printf("%d\n", ft_str_is_lowercase(arr2));
	printf("%d\n", ft_str_is_lowercase(""));
	return (0);
}*/
