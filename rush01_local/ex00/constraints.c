int		ft_c_up(char **arr, int pos, int size, int num);
int		ft_c_down(char **arr, int pos, int size, int num);
int		ft_c_left(char **arr, int pos, int size, int num);
int		ft_c_right(char **arr, int pos, int size, int num);
int		ft_strlen(char *str);
float	ft_is_squared(int num);

int	ft_count_constraints(char **arr, int pos, char *str, int num)
{
	int	size;
	int	l1;
	int	l2;
	int	c1;
	int	c2;

	size = ft_is_squared(ft_strlen(str));
	if (num == size)
	{
		c1 = (ft_c_up(arr, pos, size, num) + '0' = str[pos % size]);
		l1 = (ft_c_left(arr, pos, size, num) + '0' = str[pos % size + 2 * size]);
	}
	else
	{
		c1 = (ft_c_up(arr, pos, size, num) + '0' < str[pos % size]);
		l1 = (ft_c_left(arr, pos, size, num) + '0' < str[pos % size + 2 * size]);
	}
	c2 = (ft_c_down(arr, pos, size, num) + '0' <= str[pos % size + size]);
	l2 = (ft_c_right(arr, pos, size, num) + '0' <= str[pos % size + 3 * size]);
	return (c1 && c2 && l1 && l2);
}

int	ft_c_up(char **arr, int pos, int size, int num)
{
	int	i;
	int	max;
	int	count;
	int	comp;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (i == (int)(pos / size))
			comp = num;
		else
			comp = arr[i][pos % size] - '0';
		if ((comp != 0) && (comp > max))
		{
			max = comp;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_c_down(char **arr, int pos, int size, int num)
{
	int	i;
	int	max;
	int	count;
	int	comp;

	i = size - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (i == (int)(pos / size))
			comp = num;
		else
			comp = arr[i][pos % size] - '0';
		if ((comp != 0) && (comp > max))
		{
			max = comp;
			count++;
		}
		i--;
	}
	return (count);
}

int	ft_c_left(char **arr, int pos, int size, int num)
{
	int	j;
	int	max;
	int	count;
	int	comp;

	j = 0;
	max = 0;
	count = 0;
	while (j < size)
	{
		if (j == pos % size)
			comp = num;
		else
			comp = arr[(int)(pos / size)][j] - '0';
		if ((comp != 0) && (comp > max))
		{
			max = comp;
			count++;
		}
		j++;
	}
	return (count);
}

int	ft_c_right(char **arr, int pos, int size, int num)
{
	int	j;
	int	max;
	int	count;
	int	comp;

	j = size - 1;
	max = 0;
	count = 0;
	while (j >= 0)
	{
		if (j == pos % size)
			comp = num;
		else
			comp = arr[(int)(pos / size)][j] - '0';
		if ((comp != 0) && (comp > max))
		{
			max = comp;
			count++;
		}
		j--;
	}
	return (count);
}
