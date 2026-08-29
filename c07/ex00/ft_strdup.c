#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i;
	int	len;
	char	*dest;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	len++;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
	return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	*original = "con Franco esto no pasaba";
	char	*duplicado;

	printf("Original:  %s\n", original);

	duplicado = ft_strdup(original);

	if (duplicado == NULL)
	{
		printf("Error: No se pudo asignar memoria.\n");
		return (1);
	}

	printf("Duplicado: %s\n", duplicado);
	
	free(duplicado);
	
	return (0);
}
*/
