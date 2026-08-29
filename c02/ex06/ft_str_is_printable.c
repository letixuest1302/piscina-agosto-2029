/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:54:40 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/17 12:41:42 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	arr1[5]= "uiop";
	char	arr2[5]= "BfdE";

	printf("%d\n", ft_str_is_printable(arr1));
	printf("%d\n", ft_str_is_printable(arr2));
	printf("%d\n", ft_str_is_printable("ñ"));
	return(0);
}*/
