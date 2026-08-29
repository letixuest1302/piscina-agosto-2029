/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:41:02 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:41:05 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	extract_group(char *str, int start, char *group)
{
	int	pad;
	int	j;

	pad = 0;
	if (start < 0)
	{
		pad = -start;
		start = 0;
	}
	j = 0;
	while (j < pad)
		group[j++] = '0';
	while (j < 3)
		group[j++] = str[start++];
	group[3] = '\0';
}

void	flush_words(t_out *out)
{
	int	i;

	i = 0;
	while (i < out->count)
	{
		if (i > 0)
			ft_putstr(" ");
		ft_putstr(out->words[i]);
		i++;
	}
	ft_putstr("\n");
}
