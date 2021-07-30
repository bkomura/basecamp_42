#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	range_size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}	
	*range = (int*) malloc ((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	range_size = 0;
	while(range_size < (max - min))
	{
		(*range)[range_size] = min + range_size;
		range_size++;
	}
	return (range_size);
}
