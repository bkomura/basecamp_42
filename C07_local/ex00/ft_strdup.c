#include<stdlib.h>

int	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	char *str;
	int	len;
	int	i;

	len = ft_strlen(src);
	str = (char*) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while(src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
