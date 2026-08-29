/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:41:02 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:41:05 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*dict_lookup(t_dict *dict, char *key)
{
	while (dict)
	{
		if (ft_strcmp(dict->key, key) == 0)
			return (dict->val);
		dict = dict->next;
	}
	return (NULL);
}

int	convert_hundreds(char *group, t_dict *dict, t_out *out)
{
	char	key[2];
	char	*word;

	if (group[0] == '0')
		return (1);
	key[0] = group[0];
	key[1] = '\0';
	word = dict_lookup(dict, key);
	if (!word)
		return (0);
	out->words[out->count++] = word;
	word = dict_lookup(dict, "100");
	if (!word)
		return (0);
	out->words[out->count++] = word;
	return (1);
}

static int	convert_tens(char *group, t_dict *dict, t_out *out)
{
	char	key[3];
	char	*word;

	if (group[1] == '1')
	{
		word = dict_lookup(dict, &group[1]);
		if (!word)
			return (0);
		out->words[out->count++] = word;
		return (2);
	}
	if (group[1] != '0')
	{
		key[0] = group[1];
		key[1] = '0';
		key[2] = '\0';
		word = dict_lookup(dict, key);
		if (!word)
			return (0);
		out->words[out->count++] = word;
	}
	return (1);
}

static int	convert_units(char *group, t_dict *dict, t_out *out)
{
	char	key[2];
	char	*word;

	if (group[2] == '0')
		return (1);
	key[0] = group[2];
	key[1] = '\0';
	word = dict_lookup(dict, key);
	if (!word)
		return (0);
	out->words[out->count++] = word;
	return (1);
}

int	convert_tens_units(char *group, t_dict *dict, t_out *out)
{
	int	r;

	r = convert_tens(group, dict, out);
	if (r == 0)
		return (0);
	if (r == 2)
		return (1);
	return (convert_units(group, dict, out));
}
