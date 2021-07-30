int		ft_is_safe(char **arr, int pos, char *str, int num);
int		ft_lin(char **arr, int lin, int num, int size);
int		ft_col(char **arr, int col, int num, int size);
int		ft_strlen(char *str);
int		ft_count_constraints(char **arr, int pos, char *str, int num);
int		ft_strlen(char *str);
float	ft_is_squared(int num);

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
				if (ft_is_safe(arr, i, str, count) > 0)
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

int	ft_is_safe(char **arr, int pos, char *str, int num)
{
	int	lin;
	int	col;
	int	check;
	int	check_cons;
	int	size;

	size = (int)ft_is_squared(ft_strlen(str));
	lin = pos / size;
	col = pos % size;
	check = !ft_lin(arr, lin, num, size) && !ft_col(arr, col, num, size);
	check_cons = ft_count_constraints(arr, pos, str, num);
	return (check && check_cons);
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
