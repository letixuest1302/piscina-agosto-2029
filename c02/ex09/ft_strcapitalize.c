/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:01:24 by lesainz           #+#    #+#             */
/*   Updated: 2026/08/25 11:09:01 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // Necesario para printf en el main

char	ft_strupcase(char c)
{
	if ((c >= 'a' && c <= 'z'))
		c = c - 32;
	return (c);
}

char	ft_strlowercase(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		c = c + 32;
	return (c);
}

int	ft_is_alpha(char c)
{
	if ((c <= 'z' && c >= 'a')
		|| (c <= 'Z' && c >= 'A')
		|| (c <= '9' && c >= '0'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	str[0] = ft_strupcase(str[0]);
	while (str[i])
	{
		if (ft_is_alpha(str[i - 1]) && ft_is_alpha (str[i]))
		{
			str[i] = ft_strlowercase(str[i]);
		}
		else if (!(ft_is_alpha(str[i - 1])) && (ft_is_alpha(str[i])))
		{
			str[i] = ft_strupcase(str[i]);
		}
		i++;
	}
	return (str);
}
/*
int     main(void)
{
	char str[] = "hoL4, tengo calor y estoy feliz";
	
	printf ("Before: %s\n", str);
	printf ("After: %s\n", ft_strcapitalize(str));
	
	return (0);
}*/
