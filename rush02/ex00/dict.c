/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:40:29 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:40:31 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static t_dict	*create_node(char *key, char *val)
{
	t_dict	*node;

	node = (t_dict *)malloc(sizeof(t_dict));
	if (!node)
		return (NULL);
	node->key = ft_strtrim(key);
	node->val = ft_strtrim(val);
	node->next = NULL;
	if (!node->key || !node->val || !ft_is_valid_number(node->key))
	{
		if (node->key)
			free(node->key);
		if (node->val)
			free(node->val);
		free(node);
		return (NULL);
	}
	return (node);
}

static int	add_entry(t_dict **head, char *line)
{
	int		i;
	t_dict	*node;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (line[i] != ':')
		return (0);
	line[i] = '\0';
	node = create_node(line, &line[i + 1]);
	if (!node)
		return (0);
	node->next = *head;
	*head = node;
	return (1);
}

static int	process_lines(char *content, t_dict **head)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (content[i])
	{
		if (content[i] == '\n')
		{
			content[i] = '\0';
			if (ft_strlen(&content[start]) > 0)
			{
				if (!add_entry(head, &content[start]))
					return (0);
			}
			start = i + 1;
		}
		i++;
	}
	if (ft_strlen(&content[start]) > 0)
		if (!add_entry(head, &content[start]))
			return (0);
	return (1);
}

t_dict	*parse_dict(char *filename)
{
	char	*content;
	t_dict	*head;

	content = read_file(filename);
	if (!content)
		return (NULL);
	head = NULL;
	if (!process_lines(content, &head))
	{
		free_dict(head);
		free(content);
		return (NULL);
	}
	free(content);
	return (head);
}

void	free_dict(t_dict *dict)
{
	t_dict	*tmp;

	while (dict)
	{
		tmp = dict->next;
		free(dict->key);
		free(dict->val);
		free(dict);
		dict = tmp;
	}
}
