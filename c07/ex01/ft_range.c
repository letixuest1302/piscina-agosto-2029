#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	length;
	
	if (min >= max)
	return (NULL);

	length = max - min;
	tab = (int *)malloc(sizeof(int) * length);
	if (!tab)
		return (NULL);

	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
/*
int	main(void)
{
	int	*rango;
	int	min = 5;
	int	max = 10;
	int	i;
	
	rango = ft_range(min, max);
	
	if (rango == NULL)
	{
		printf("Error: Rango inválido o fallo de malloc.\n");
		return (1);
	}
	
	printf("Rango de %d a %d:\n", min, max);
	i = 0;
	while (i < (max - min))
	{
		printf("[%d] ", rango[i]);
		i++;
	}
	printf("\n");
	free(rango);
	return (0);
}*/
