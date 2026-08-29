
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	lg = 0;

	while (str[lg])
		lg++;
	return (lg);
}

char	*ft_sep_lines(char *str, int depth, char *result, char *charset, int lg_sep)
{
	int	count = 0;
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	lg = 0;


	while (str[i])
	{
		j = 0;
		while (str[i + j] == charset[j] && charset[j])
		{
			if (j == lg_sep)
				count++;
			j++;
		}
		if (count == depth)
			lg++;
		i++;
	}
	result = (char *)malloc((lg + 1) * sizeof(char));
	if (!result)
		return NULL;
	count = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == charset[j] && charset[j])
		{
			if (j == lg_sep)
				count++;
			j++;
		}
		if (count == depth)
		{
			result[k] = str[i];
			k++;
		}
		i++;
	}
	result[k] = '\0';
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int	depth = 1;
	int	i = 0;
	int	j = 0;
	int	lg_sep = 0;

	lg_sep = ft_strlen(charset) - 1;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == charset[j] && charset[j])
		{
			if (j == lg_sep)
				depth++;
			j++;
		}
		i++;
	}
	result = (char **)malloc((depth + 1) * sizeof(char *));
	if (!result)
		return NULL;
	i = 0;
	while (i < depth)
	{
		result[i] = ft_sep_lines(str, i, result[i], charset, lg_sep);
		i++;
	}
	result[depth] = NULL;
	return (result);
}

int	main(int argc, char **argv)
{
	char	**result;
	int	i = 0;

	if (argc != 3)
	{
		write(2, "Error!", 7);
		return (1);
	}
	result = ft_split(argv[1], argv[2]);
	while (result[i])
	{
		printf("result[%d] = %s\n", i, result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);i++;
	}
	free(result);
	return (0);
}
