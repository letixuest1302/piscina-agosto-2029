#include <stdlib.h>
#include <stdio.h>

int    ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;
	int	size;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}

	size = max - min;
	tab = (int *)malloc(sizeof(int) * size);
	
	if (!tab)
	{
        	*range = NULL;
        	return (-1);
    	}
	
	i = 0;
	while (min < max)
	{
        	tab[i] = min;
        	i++;
		min++;
	}
	
	*range = tab;
	return (size);
}

int    main(void)
{
	int	rango_reserva;
	int	tamano;
	int	min = 10;
	int	max = 15;
	int	i;
	
	tamano = ft_ultimate_range(&rango_reserva, min, max);
	if (tamano == -1)
	{
        	printf("Error de malloc\n");
		return (1);
	}
	
	printf("Tamaño retornado: %d\n", tamano);
	
	if (tamano > 0)
	{
        	printf("Contenido del rango: ");
		i = 0;
		while (i < tamano)
        	{	
            		printf("%d ", rango_reserva[i]);
            		i++;
        	}
        	printf("\n");
		free(rango_reserva);
	}
	else
	{
		printf("Rango vacío (NULL)\n");
	}
	return (0);
}
