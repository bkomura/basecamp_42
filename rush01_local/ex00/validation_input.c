#include <stdlib.h>

float	ft_is_squared(int num);
void	ft_set_args(char argv[], int size);
int		ft_is_number(char *str, int num);
int		ft_sum_validation(char *str, int size);

int	ft_is_valid(char *str, int *num)
{
	int		i;
	int		i_var;
	float	f_var;

	i = 0;
	f_var = ft_is_squared((*num + 1) / 2);
	i_var = f_var;
	if (!(i_var == f_var))
		return (0);
	*num = i_var;
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
