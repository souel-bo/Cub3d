#include "../includes/libft.h"

int	ft_count_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
