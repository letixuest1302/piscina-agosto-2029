/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:04:35 by seantoni          #+#    #+#             */
/*   Updated: 2023/11/08 20:15:08 by seantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_str_strlen(int size, char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_strlen(strs[i]);
		i++;
	}
	return (j);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	if (dest[i] == 0)
	{
		while (src[j] != 0)
		{
			dest[i + j] = src[j];
			j++;
		}
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len_sep;
	int		len_strs;
	char	*strd;

	strd = (char *)malloc(1);
	*strd = 0;
	if (size == 0)
		return (strd);
	len_sep = ft_strlen(sep);
	len_strs = ft_str_strlen(size, strs);
	strd = (char *)malloc(len_strs + (len_sep * (size - 1)) + 1);
	i = 0;
	while (i < size)
	{
		ft_strcat(strd, strs[i]);
		if (!(i == (size - 1)))
			ft_strcat(strd, sep);
		i++;
	}
	return (strd);
}
