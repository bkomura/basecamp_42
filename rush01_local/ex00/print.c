#include<unistd.h>

void	ft_putchar(char c);

void	ft_print(char **arr, int size)
{
	int	lin;
	int	col;

	lin = 0;
	while (lin < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(arr[lin][col]);
			if (col != size - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		lin++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
