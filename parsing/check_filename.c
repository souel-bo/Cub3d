#include "../includes/cub.h"

char	*get_name(char *str)
{
	int		i;
	int		len;
	char	*name;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i <= len - 1)
	{
		if (str[len] == '/')
		{
			i = len;
			break ;
		}
		len--;
	}
	i++;
	name = ft_substr(str, i, ft_strlen(str));
	return (name);
}

int	ft_check_filename(char *str)
{
	int		i;
	char	*name;

	name = get_name(str);
	if (name[0] == '.')
		return (free(name), 1);
	else
	{
		i = 0;
		while (name[i])
		{
			if (name[i] == '.')
				break ;
			i++;
		}
		if (!(name[i + 1] == 'c' && name[i + 1] == 'u' && name[i + 1] == 'b'
				&& name[i + 1] == '\0'))
			return (free(name), 1);
	}
	return (free(name), 0);
}
