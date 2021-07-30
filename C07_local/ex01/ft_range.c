#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	arr = (int*) malloc((max - min) * sizeof(int));
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
