/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:26:27 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/18 10:32:28 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char arr1[5] = "YtEf";
	char arr2[5] = "YmcY";

	printf("%d\n", ft_str_is_uppercase(arr1));
	printf("%d\n", ft_str_is_uppercase(arr2));
	printf("%d\n", ft_str_is_uppercase(""));
	return (0);
}*/
