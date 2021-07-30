#include<unistd.h>
#include<stdlib.h>

void	ft_error(void);
void	ft_print(char **arr, int size);
void	ft_create_map(char **arr, int size, char *str);
int		ft_fill(char **arr, char *str, int size);
int		ft_is_valid(char *str, int *num);
int		ft_strlen(char *str);
int		ft_is_empty(char **arr, int size);

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
