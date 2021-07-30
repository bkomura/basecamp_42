#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c);

void	error(int x, int y)
{
	if ((x == 0 || y == 0) || (x < 0 || y < 0))
	{
		write(1, "Digite novamente!", 17);
	}
}

void	rush(int x, int y)
{
	int	col;
	int	lin;
	int	cond1;
	int	cond2;

	lin = 1;
	error(x, y);
	while (lin <= y)
	{
		col = 1;
		while (col <= x)
		{
			cond1 = ((col == 1 && lin == 1) || ((col == x && lin == y));
			cond2 = (col != 1 && lin != 1);
			if (cond1 && cond2))
				ft_putchar('/');
			else if ((col == 1 && lin == y) || (col == x && lin == 1))
				ft_putchar('\\');
			else if (col == 1 || lin == 1 || col == x || lin == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
			col++;
		}
		lin++;
		write(1, "\n", 1);
	}
}
