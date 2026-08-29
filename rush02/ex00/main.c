/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:41:24 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:41:25 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	get_args(int argc, char **argv, char **dict_path, char **num_str)
{
	*dict_path = "numbers.dict";
	if (argc == 2)
		*num_str = argv[1];
	else if (argc == 3)
	{
		*dict_path = argv[1];
		*num_str = argv[2];
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*num_str;
	t_dict	*dict;

	if (!get_args(argc, argv, &dict_path, &num_str))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_is_valid_number(num_str))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	dict = parse_dict(dict_path);
	if (!dict || !convert_number(num_str, dict))
		write(1, "Dict Error\n", 11);
	if (dict)
		free_dict(dict);
	return (0);
}
