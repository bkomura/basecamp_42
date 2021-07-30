#include <stdlib.h>

void	ft_set_zero(char **matrix, int size);
void	ft_fill_extremes(char **arr, char *str, int size);

void	ft_create_map(char **matrix, int size, char *str)
{
	int	i;

	i = 0;
	free(matrix);
	matrix = malloc ((size + 1) * sizeof (char *));
	while (i < size)
	{
		matrix[i] = malloc ((size + 1) * size);
		i++;
	}
	ft_set_zero(matrix, size);
	ft_fill_extremes(matrix, str, size);
}

void	ft_set_zero(char **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	ft_is_empty(char **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i][j] == '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_position(int count, int size, int type)
{
	if (type == 0)
	{
		if (count / size == 0)
			return (0);
		else if (count / size == 1)
			return (size - 1);
		else
			return (count % size);
	}
	else
	{
		if (count / size == 2)
			return (0);
		else if (count / size == 3)
			return (size - 1);
		else
			return (count % size);
	}
}
