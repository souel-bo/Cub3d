#include "../includes/cub.h"

int	ft_check_filename(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[len] == '\n')
		len--;
	if (str[len] == 'b')
		len--;
	else
		return (1);
	if (str[len] == 'u')
		len--;
	else
		return (1);
	if (str[len] == 'c')
		len--;
	else
		return (1);
	if (str[len] != '.')
		return (1);
	if (open(str, O_RDONLY) < 0)
		return (1);
	return (0);
}
