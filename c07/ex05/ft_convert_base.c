
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	lg = 0;

	while (*str)
	{
		str++;
		lg++;
	}
	return (lg);
}

int	ft_power(int base, int power)
{
	int	result;

	if(power == 0)
		return (1);
	if (power > 1)
		result = base * ft_power(base, power - 1);
	else
		return (base);
	return (result);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i = 0;
	int	j = 0;
	int	result = 0;
	int	lg_base = 0;
	int	lg_nbr = 0;

	lg_nbr = ft_strlen(nbr);
	lg_base = ft_strlen(base);
	while (nbr[j])
	{
		i = 0;
		while (base[i])
		{
			if (nbr[j] == base[i])
				result = result + i * ft_power(lg_base, lg_nbr - j - 1);
			i++;
		}
		j++;
	}
	printf("atoied_nbr = %d\n", result);
	return (result);
}

int	ft_exp_nbr(int nbr)
{
	int	exp = 1;

	while (nbr > 9)
	{
		nbr = nbr / 10;
		exp++;
	}
	printf("lg_nbr = %d\n", exp);
	return (exp);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int	lg_nbr = 0;
	int	temp = 0;
	int	lg_result = 1;
	int	atoied_nbr = 0;
	int     lg_base = 0;
	int	i = 0;

	lg_base = ft_strlen(base_to);
	printf("lg_base_to = %d\n", lg_base);
	atoied_nbr = ft_atoi_base(nbr, base_from);
	temp = atoied_nbr;
	lg_nbr = ft_exp_nbr(atoied_nbr);
	while (temp >= lg_base)
	{
		temp = temp / lg_base;
		lg_nbr--;
		lg_result++;
	}
	printf("lg_result = %d\n", lg_result);
	result = (char *)malloc(lg_result + 1 * sizeof(char));
	if (!result)
		return (NULL);
	lg_nbr = ft_exp_nbr(atoied_nbr);
	i = lg_result - 1;
	while (atoied_nbr >= lg_base)
	{
		result[i] = base_to[atoied_nbr % lg_base];
		atoied_nbr = atoied_nbr / lg_base;
		lg_nbr--;
		i--;
	}
	result[i] = base_to[atoied_nbr % lg_base];
	result[lg_result] = '\0';
	return (result);
}

int	main(void)
{
	char	*nbr = "123456";
	char	*base_from = "0123456789";
	char	*base_to = "01";
	char	*result;

	result = ft_convert_base(nbr, base_from, base_to);
	printf("result = %s\n", result);
	return (0);
}
