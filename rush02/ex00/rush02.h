/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaron <ecaron@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:42:47 by ecaron            #+#    #+#             */
/*   Updated: 2026/08/29 17:42:49 by ecaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char			*key;
	char			*val;
	struct s_dict	*next;
}	t_dict;

typedef struct s_out
{
	char	**words;
	int		count;
}	t_out;

/* String utils */
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
int		ft_is_valid_number(char *str);

/* Parsing utils */
char	*ft_strtrim(char *str);
char	*read_file(char *filename);

/* Dictionary functions */
t_dict	*parse_dict(char *filename);
char	*dict_lookup(t_dict *dict, char *key);
void	free_dict(t_dict *dict);

/* Conversion functions */
int		convert_number(char *num_str, t_dict *dict);
int		convert_hundreds(char *group, t_dict *dict, t_out *out);
int		convert_tens_units(char *group, t_dict *dict, t_out *out);
void	extract_group(char *str, int start, char *group);
void	flush_words(t_out *out);

#endif
