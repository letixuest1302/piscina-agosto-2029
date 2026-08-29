/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:40:59 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:41:02 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	collect_magnitude(int mag_index, t_dict *dict, t_out *out)
{
	char	*mag;
	char	*word;
	int		i;

	if (mag_index == 0)
		return (1);
	mag = (char *)malloc(sizeof(char) * (mag_index * 3 + 2));
	if (!mag)
		return (0);
	mag[0] = '1';
	i = 1;
	while (i <= mag_index * 3)
		mag[i++] = '0';
	mag[i] = '\0';
	word = dict_lookup(dict, mag);
	free(mag);
	if (!word)
		return (0);
	out->words[out->count++] = word;
	return (1);
}

static int	process_groups(char *str, int len, t_dict *dict, t_out *out)
{
	int		num_groups;
	int		i;
	int		start;
	char	group[4];

	num_groups = (len + 2) / 3;
	i = 0;
	while (i < num_groups)
	{
		start = len - (num_groups - i) * 3;
		extract_group(str, start, group);
		if (ft_strcmp(group, "000") != 0)
		{
			if (!convert_hundreds(group, dict, out))
				return (0);
			if (!convert_tens_units(group, dict, out))
				return (0);
			if (!collect_magnitude(num_groups - 1 - i, dict, out))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	convert_nonzero(char *num_str, t_dict *dict)
{
	int		len;
	int		num_groups;
	t_out	out;

	len = ft_strlen(num_str);
	num_groups = (len + 2) / 3;
	out.count = 0;
	out.words = (char **)malloc(sizeof(char *) * (num_groups * 5 + 1));
	if (!out.words)
		return (0);
	if (!process_groups(num_str, len, dict, &out))
	{
		free(out.words);
		return (0);
	}
	flush_words(&out);
	free(out.words);
	return (1);
}

int	convert_number(char *num_str, t_dict *dict)
{
	char	*word;

	while (*num_str == '0' && *(num_str + 1) != '\0')
		num_str++;
	if (ft_strcmp(num_str, "0") == 0)
	{
		word = dict_lookup(dict, "0");
		if (!word)
			return (0);
		ft_putstr(word);
		ft_putstr("\n");
		return (1);
	}
	return (convert_nonzero(num_str, dict));
}
