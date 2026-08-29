
#include <stdlib.h>
#include <unistd.h>
#include "ft_strs_to_tab.h" 

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strcopy(char *dest, char *src)
{
	int	i = 0;

	while (src[i++])
		dest[i - 1] = src[i - 1];
	dest[i - 1] = '\0';
	return (dest);
}

t_stock_str	*ft_malloc_error(t_stock_str *par, int i)
{
	while (--i >= 0)
	{
		free(par[i].str);
		free(par[i].copy);
	}
	free (par);
	return (NULL);
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;

	i = 0;
	t_stock_str *par;

	par = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!par)
		return (NULL);
	while (i < ac)
	{
		par[i].size = ft_strlen(av[i]);
		par[i].str = (char *)malloc((par[i].size + 1) * sizeof(char));
		par[i].copy = (char *)malloc((par[i].size + 1) * sizeof(char));
		if (!par[i].str || !par[i].copy)
			return (ft_malloc_error(par, i));
		ft_strcopy(par[i].str, av[i]);
		ft_strcopy(par[i].copy, av[i]);
		i++;
	}
	par[i].str = NULL;
	return (par);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr("size = ");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr("str = ");
		ft_putstr(par[i].str);
		ft_putstr("\n");
		free(par[i].str);
		ft_putstr("copy = ");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		free(par[i].copy);
		i++;
	}
}

int     main(int argc, char **argv)
{
	struct s_stock_str	*result;
	char	**str;
	int	lg = 0;
	int	i = 1;

	str = (char **)malloc((argc + 1) * sizeof(char *));
	if (!str)
		return (1);
	while (i < argc)
	{
		lg = ft_strlen(argv[i]);
		str[i - 1] = (char *)malloc((lg + 1) * sizeof(char));
		if (!str[i - 1])
		{
			while (--i >= 0)
				free (str[i - 1]);
			free (str);
			return (1);
		}
		ft_strcopy(str[i - 1], argv[i]);
		i++;
	}
	result = ft_strs_to_tab(argc - 1, str);
	ft_show_tab(result);
	i = 0;
	while (i < argc - 1)
	{
		free (str[i]);
		i++;
	}
	free (result);
	free (str);
	return (0);
}
