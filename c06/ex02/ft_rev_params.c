#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_nl(char *str)
{
	int	i = 0;

	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}
/*
int	main(int argc, char **argv)
{
	int	j;
	
	j = argc - 1;
	while(j > 0)
	{
		ft_putstr_nl(argv[j]);
		j--;
        }
        return (0);
}*/


