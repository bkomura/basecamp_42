int		ft_strlen(char *str);
int		ft_position(int count, int size, int type);
void	ft_fill_down(int col, int size, char **arr);
void	ft_fill_up(int col, int size, char **arr);
void	ft_fill_left(int lin, int size, char **arr);
void	ft_fill_right(int lin, int size, char **arr);

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
