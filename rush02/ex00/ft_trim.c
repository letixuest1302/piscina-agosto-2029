/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:39:11 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:39:14 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

char	*ft_strtrim(char *str)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	if (!str)
		return (NULL);
	start = 0;
	while (str[start] && is_space(str[start]))
		start++;
	end = ft_strlen(str) - 1;
	while (end >= start && is_space(str[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	trimmed = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed[i++] = str[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
