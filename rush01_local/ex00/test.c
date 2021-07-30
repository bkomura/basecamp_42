#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void	ft_putchar(char c);
void	ft_error(void);
void	ft_print(char **arr, int size);
void	ft_create_map(char **arr, int size, char *str);
void	ft_fill_down(int col, int size, char **arr);
void	ft_fill_up(int col, int size, char **arr);
void	ft_fill_left(int lin, int size, char **arr);
void	ft_fill_right(int lin, int size, char **arr);
void	ft_set_zero(char **matrix, int size);
void	ft_fill_extremes(char **arr, char *str, int size);
void	ft_assign_value(char **matrix, int size);
void	ft_set_args(char argv[], int size);
float	ft_is_squared(int num);
int		ft_fill(char **arr, char *str, int size);
int		ft_is_valid(char *str, int *size);
int		ft_strlen(char *str);
int		ft_is_number(char *str, int num);
int		ft_sum_validation(char *str, int size);
int		ft_loop_opt(int i, int j, char **arr, char *str);
int		ft_is_safe(char **arr, int pos, int size, int num);
int		ft_lin(char **arr, int lin, int num, int size);
int		ft_col(char **arr, int col, int num, int size);
int		ft_position(int count, int size, int type);

int	main(int argc, char *argv[])
{
	int		size;
	int		*pnt_i;
	char	**matrix;

	size = ft_strlen(argv[1]);
	pnt_i = &size;
	matrix = malloc ((size + 1) * sizeof (char));
	if ((argc != 2) || (ft_is_valid(argv[1], pnt_i) == 0))
		ft_error();
	else
	{
		ft_create_map(matrix, size, argv[1]);
		ft_fill(matrix, argv[1], size);
		ft_print(matrix, size);
	}
	return (0);
}

int	ft_fill(char **arr, char *str, int size)
{
	int	i;
	int	count;

	i = 0;
	while (i < size * size)
	{
		if (arr[i / size][i % size] == '0')
		{
			count = 1;
			while (count <= size)
			{
				if (ft_is_safe(arr, i, size, count) > 0)
				{
					arr[i / size][i % size] = count + '0';
					if (ft_fill(arr, str, size) > 0)
						return (1);
					else
						arr[i / size][i % size] = '0';
				}
				count++;
			}
		}
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_is_safe(char **arr, int pos, int size, int num)
{
	int	lin;
	int	col;
	int	check;

	lin = pos / size;
	col = pos % size;
	check = !ft_lin(arr, lin, num, size) && !ft_col(arr, col, num, size);
	return (check);
}

int	ft_lin(char **arr, int lin, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[lin][i] == num + '0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_col(char **arr, int col, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i][col] == num + '0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_fill_extremes(char **arr, char *str, int size)
{
	int	count;
	int	lin;
	int	col;

	count = 0;
	while (str[count])
	{
		lin = ft_position(count, size, 0);
		col = ft_position(count, size, 1);
		if (str[count] == '1')
			arr[lin][col] = size + '0';
		else if (str[count] == size + '0')
		{
			if (count / size == 0)
				ft_fill_down(col, size, arr);
			else if (count / size == 1)
				ft_fill_up(col, size, arr);
			else if (count / size == 2)
				ft_fill_right(lin, size, arr);
			else
				ft_fill_left(lin, size, arr);
		}
		count++;
	}
}

void	ft_fill_down(int col, int size, char **arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i][col] = i + '1';
		i++;
	}
}

void	ft_fill_up(int col, int size, char **arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[size - i - 1][col] = i + '1';
		i++;
	}
}

void	ft_fill_right(int lin, int size, char **arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[lin][i] = i + '1';
		i++;
	}
}

void	ft_fill_left(int lin, int size, char **arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[lin][size - i - 1] = i + '1';
		i++;
	}
}

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

int	ft_is_valid(char *str, int *size)
{
	int		i;
	int		i_var;
	float	f_var;

	i = 0;
	f_var = ft_is_squared((*size + 1) / 2);
	i_var = f_var;
	if (!(i_var == f_var))
		return (0);
	*size = i_var;
	if (ft_is_number(str, i_var) == 0)
		return (0);
	ft_set_args(str, i_var * i_var);
	return (i_var);
}

float	ft_is_squared(int num)
{
	float	temp;
	float	sqrt;

	sqrt = num / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (num / temp + temp) / 2;
	}
	return (sqrt);
}

int	ft_is_number(char *str, int num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i % 2) == 0)
			if (!(str[i] <= num + '0' && str[i] >= '1'))
				return (0);
		i++;
	}
	return (1);
}

void	ft_set_args(char argv[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		argv[i] = argv[i * 2];
		i++;
	}
	argv[i] = '\0';
}

int	ft_sum_validation(char *str, int size)
{
	int	sum_col;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		sum_col = (int)str[i] + (int)str[i + size];
		if ((sum_col > size + 1) || sum_col < 3)
			return (0);
		i++;
	}
	i = i + size;
	j = 0;
	while (j < size)
	{
		sum_col = (int)str[i + j] + (int)str[i + j + size];
		if ((sum_col > size + 1) || sum_col < 3)
			return (0);
		j++;
	}
	return (1);
}
